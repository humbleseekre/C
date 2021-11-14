"""
This file contains code for Beverage class
"""


class Beverage:

    """
    This class holds information about beverage
    """
    def __init__(self, name, ingredients={}):
        """
        constructor of class
        :param name: name of beverage
        :param ingredients: dictionary ('ingredient': quantity)
        """
        self.name = name
        self._ingredients = ingredients

    def get_ingredients(self):
        return self._ingredients
		
"""
This file contains code for ingredient clas
"""

from threading import RLock


class Ingredient:
    """
    class for Ingredient
    Key thing to note here is for each ingredient object
    one lock will be assign , at a time only one thread will be
    able to access the ingredient
    """
    def __init__(self, name, quantity):
        self._name = name
        self._quantity = quantity
        self._lock = RLock()
        self._timeout = 30  # 30 sec

    def get_quantity(self):
        """
        return: quantity available
        """
        return self._quantity

    def get_name(self):
        """
        return: name of ingredient
        """
        return self._name

    def use_ingredient(self, quantity):
        """
        subtract quantity to ingredient
        :param quantity: quantity to be subtracted by thread
        :return: boolean , whether the process is success
        """
        if quantity < 0:
            raise Exception("Cannot subtract quantity "
                            "= {}".format(quantity))
        self._lock.acquire(timeout=self._timeout)
        if self._quantity < quantity:
            self._lock.release()
            return False
        self._quantity -= quantity
        self._lock.release()
        return True

    def add_quantity(self, quantity):
        """
        add quantity to ingredient
        :param quantity : quantity added to
        """
        if quantity < 0:
            raise Exception("Cannot add negative quantity")
        self._lock.acquire(timeout=self._timeout)
        self._quantity += quantity
        self._lock.release()
		
	"""
This file contains code for Inventory class
"""
from src.main.ingredient import Ingredient


class Inventory:
    """
    Inventory class
    """
    def __init__(self, logger):

        self._ingredients = dict()
        self._logger = logger

    def get_current_inventory(self):
        """
        :return: This function returns current state of inventory in
        form of dict ('ingredient': quantity)
        """

        available_ingredient = {}
        for ingredient in self._ingredients:
            available_ingredient[ingredient] = self._ingredients[ingredient]._quantity

        return available_ingredient

    def add_ingredients(self, total_items_quantity):
        """
        add ingredients to inventory
        :param total_items_quantity: dict type where key is
        ingredient name and value is its quantity
        :return: None
        """
        for item in total_items_quantity.keys():
            quantity = total_items_quantity[item]
            if item in self._ingredients:
                self._ingredients[item].add_quantity(quantity)
            else:
                ingredient = Ingredient(item, quantity)
                self._ingredients[item] = ingredient

    def check_availability(self, ingredients_list):
        """
        this function checks availability of ingredient provided
        dict of ingredient where key is ingredient name and value
        is quantity required
        :param ingredients_list: list of ingredients
        :return: Boolean value whether all ingredient available or not
        """
        for ingredient in ingredients_list:
            ingredient_name = ingredient.get_name()
            if ingredient_name in self._ingredients \
                    and self._ingredients[ingredient_name].get_quantity() < ingredient.get_quantity():
                return False
            elif ingredient_name not in self._ingredients:
                return False
        return True

    def take_ingredient(self, ingredients_dict):
        """
        deduct ingredient from inventory
        take_ingredient is like transaction , either you commit or rollback
        :param ingredients_dict: dictionary where key is ingredient name and
        value is quantity required(will be deducted if transaction is committed)
        :return: boolean whether the whole process completed
        """
        ingredient_used = {}
        is_possible = True
        for ingredient_name in ingredients_dict.keys():
            quantity = ingredients_dict[ingredient_name]
            if ingredient_name in self._ingredients and \
                    self._ingredients[ingredient_name].use_ingredient(quantity):
                ingredient_used[ingredient_name] = quantity
            else:
                is_possible = False
                break

        # Commit
        if is_possible:
            return True

        # Rollback
        for ingredient in ingredient_used.keys():
            self._ingredients[ingredient].add_quantity(ingredient_used[ingredient])
        return False

"""
This file contains code for coffee machine
"""

from src.main.inventory import Inventory
from concurrent.futures.thread import ThreadPoolExecutor
from src.main.logger import get_logger


class CoffeeMachine:

    """
    class for coffee machine
    """
    def __init__(self, slots):
        """
        constructor of the class
        :param slots: Number of slots
        """
        self._slots = slots
        self._logger = get_logger()
        self._inventory = Inventory(logger=self._logger)
        self._executor = ThreadPoolExecutor(max_workers=self._slots)
        self._supported_beverage = dict()

    def can_make_beverage(self, beverage):
        """
        check whether a beverage can be made using available ingredient
        :param beverage: beverage object
        :return: boolean value (True/False)
        """
        return self._inventory.check_availability(beverage.get_ingredients())

    def add_beverage(self, beverage_name, beverage):
        """
        add beverage to supported list
        whenever an order is placed it will first check
        whether beverage is supported by machine
        :param beverage_name: name of beverage
        :param beverage: beverage object
        :return: None
        """
        self._supported_beverage[beverage_name] = beverage

    def get_current_inventory(self):
        """
        Get the state of current inventory in form of dict('ingredient name': quantity)
        :return: dictionary
        """
        return self._inventory.get_current_inventory()

    def make_beverage(self, beverage_name):
        """
        make beverage based on beverage name
        :param beverage_name: name of beverage to make
        :return: boolean value , whether make is successful or not
        """
        if beverage_name not in self._supported_beverage:
            self._logger.info("{} is not available in the shop !!!".format(beverage_name))
            return False
        self._logger.info("Preparing beverage : {}".format(beverage_name))

        beverage = self._supported_beverage[beverage_name]

        if self._inventory.take_ingredient(beverage.get_ingredients()):
            self._logger.info("{} is prepared ".format(beverage_name))
            return True
        self._logger.info("Currently we are out of stocks for {} !!!"
                          " Try another beverage".format(beverage_name))
        return False

    def place_order(self, beverage_name):
        """
        place order for beverage name , this function will spawn a thread for each order placed
        :param beverage_name: name of beverage
        :return: returns future object
        """

        return self._executor.submit(self.make_beverage, beverage_name)

    def refill_ingredient(self, ingredient_dict):
        """
        refill ingredients in inventory
        :param ingredient_dict: dictionary with key as
        ingredient and value as quantity
        :return: None
        """

        self._inventory.add_ingredients(ingredient_dict)
		
