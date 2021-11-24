inline uint16_t Reverse16(uint16_t value)
{
    return (((value & 0x00FF) << 8) |
            ((value & 0xFF00) >> 8));
}
    
inline uint32_t Reverse32(uint32_t value) 
{
    return (((value & 0x000000FF) << 24) |
            ((value & 0x0000FF00) <<  8) |
            ((value & 0x00FF0000) >>  8) |
            ((value & 0xFF000000) >> 24));
}

int main()
{
    uint16_t num = 0x1234;
    uint32_t num32 = 0x12345678;
    printf("num is %x, after swapping number is %x", num, reverse32(num32));
    return 0;
}
