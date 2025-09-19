import math

# -------------------------------
# Q1: Circle Class
# -------------------------------
class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * (self.radius ** 2)

    def perimeter(self):
        return 2 * math.pi * self.radius


def circle_demo():
    c = Circle(5)   # example radius
    print("Circle radius:", c.radius)
    print("Area:", c.area())
    print("Perimeter:", c.perimeter())


# ----------------------------------
# Q2: Book Class
# ----------------------------------
class Book:
    def __init__(self, title, author, price):
        self.title = title
        self.author = author
        self.price = price

    def display_details(self):
        print(f"Title: {self.title}, Author: {self.author}, Price: {self.price}")

    def apply_discount(self, discount_percent):
        discount_amount = self.price * (discount_percent / 100)
        self.price -= discount_amount
        print(f"Discount of {discount_percent}% applied! New price: {self.price}")


def book_demo():
    # Create two books
    book1 = Book("Python Programming", "John Smith", 500)
    book2 = Book("Data Science Handbook", "Alice Brown", 700)

    # Display details
    print("\n--- Book Details ---")
    book1.display_details()
    book2.display_details()

    # Apply 10% discount on book2
    print("\nApplying 10% discount on book2...")
    book2.apply_discount(10)

    # Display updated details
    book2.display_details()

if __name__ == "__main__":
    print("=== Circle Demo ===")
    circle_demo()

    print("\n=== Book Demo ===")
    book_demo()
