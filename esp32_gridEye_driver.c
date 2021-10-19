/* i2c - Simple example

   Simple I2C example that shows how to initialize I2C
   as well as reading and writing from and to registers for a sensor connected over I2C.

   The sensor used in this example is a MPU9250 inertial measurement unit.

   For other examples please check:
   https://github.com/espressif/esp-idf/tree/master/examples

   See README.md file to get detailed usage of this example.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"


static const char *TAG = "i2c-gridEye-example";

#define I2C_MASTER_SCL_IO           19      /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           18      /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              I2C_NUM_0                          /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ          100000                     /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_GRID_EYE_SLAVE_ADDRESS  0x69
#define WRITE_BIT                   I2C_MASTER_WRITE                   
#define READ_BIT                    I2C_MASTER_READ
#define ACK_VAL                     0x0
#define NACK_VAL                    0x1
#define ACK_CHECK_EN                0x1
#define ACK_CHECK_DIS               0x0
#define TEMPERATURE_REGISTER        0x80


static esp_err_t i2c_master_config()
{
    i2c_config_t conf_master = {
        .mode = I2C_MODE_MASTER,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
    };
    return i2c_param_config(I2C_MASTER_NUM, &conf_master);
}

void i2c_master_init()
{
    i2c_master_config();    
    i2c_driver_install(I2C_MASTER_NUM, I2C_MODE_MASTER, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

static esp_err_t i2c_master_read_slave(uint8_t *data, size_t data_len, int reg)
{
    if(data == NULL || data_len == 0){
        return ESP_ERR_INVALID_ARG;
    }
    // 1. create handle
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    // 2. send start condition
    i2c_master_start(cmd);
    // 3. Send the peripheral address
    i2c_master_write_byte(cmd, ((I2C_GRID_EYE_SLAVE_ADDRESS << 1) | WRITE_BIT), ACK_CHECK_EN);
    // 4. send the address to read in peripheral 
    i2c_master_write_byte(cmd, reg, ACK_CHECK_EN);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, ((I2C_GRID_EYE_SLAVE_ADDRESS << 1) | READ_BIT), ACK_CHECK_EN);
    // 6. Get the data
    if(data_len > 1){
        i2c_master_read(cmd, data, data_len-1, ACK_VAL);
    }
    i2c_master_read_byte(cmd, data+data_len-1, NACK_VAL);
    // 7. send the stop sequence
    i2c_master_stop(cmd);
    // 8.
    esp_err_t ret =i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, 50 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    // vTaskDelay(100/ portTICK_RATE_MS);
    return ret;
}

int16_t readGridEyePixelValue(int pos)
{
    if(pos < 0x80){
        return -1;
    }
    uint8_t data[2] = {0};
    int16_t pixelReading = 0;
    i2c_master_read_slave(data, sizeof(data), pos);
    pixelReading = ((data[1] << 8)| (data[0]));
    if(pixelReading & (1<<11)){
        pixelReading &= ~(1<11);
        pixelReading *= -1;
    }
    return pixelReading/4;
}

void pollGridEye(){
    while(1){
        // int count = 0;
        vTaskDelay(100);
        printf("\n");
        for(int i=0; i< 8; ++i){
            // printf("%d ", readGridEyePixelValue(TEMPERATURE_REGISTER + count*2));
            for(int j=0; j < 8; ++j){
                printf(" %d ", readGridEyePixelValue(TEMPERATURE_REGISTER + i*16 + j*2));
            }
            printf("\n");
        }
        // vTaskDelay(100);
    }
}

void app_main(void){
    ESP_LOGI(TAG, "Starting GridEye Driver Code!");
    i2c_master_init();
    pollGridEye();
}

