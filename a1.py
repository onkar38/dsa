class Record:
    def __init__(self, name, number):
        self.name = name
        self.number = number
    
    def get_name(self):
        return self.name
    
    def get_number(self):
        return self.number

class HashTableLinearProbing:
    def __init__(self, size):
        self.size = size
        self.table = [None] * self.size
        self.elementCount = 0
    
    def hashFunction(self, element):
        return hash(element) % self.size
    
    def insert(self, record):
        position = self.hashFunction(record.get_name())
        while self.table[position] is not None:
            position = (position + 1) % self.size
        self.table[position] = record
        self.elementCount += 1
        print("Phone number of", record.get_name(), "is at position", position)
        
    def search(self, name):
        position = self.hashFunction(name)
        initial_position = position
        comparisons = 0
        
        while self.table[position] is not None:
            comparisons += 1
            if self.table[position].get_name() == name:
                print("Phone number found at position", position, "and total comparisons are", comparisons)
                return
            position = (position + 1) % self.size
            if position == initial_position:
                break
        print("Record not found.")
            
    def display(self):
        print("\nTelephone Book:")
        for i in range(self.size):
            if self.table[i]:
                print("Hash Value:", i, "Name:", self.table[i].get_name(), "Number:", self.table[i].get_number())
        print("The number of phonebook records in the Table are:", self.elementCount)

class HashTableDoubleHashing:
    def __init__(self, size):
        self.size = size
        self.table = [None] * self.size
        self.elementCount = 0
    
    def hashFunction1(self, element):
        return hash(element) % self.size
    
    def hashFunction2(self, element):
        return 7 - (hash(element) % 7)  # Using 7 as the prime number for double hashing
    
    def insert(self, record):
        position = self.hashFunction1(record.get_name())
        if self.table[position] is None:
            self.table[position] = record
        else:
            offset = self.hashFunction2(record.get_name())
            while self.table[position] is not None:
                position = (position + offset) % self.size
            self.table[position] = record
        self.elementCount += 1
        print("Phone number of", record.get_name(), "is at position", position)
        
    def search(self, name):
        position = self.hashFunction1(name)
        initial_position = position
        comparisons = 0
        
        while self.table[position] is not None:
            comparisons += 1
            if self.table[position].get_name() == name:
                print("Phone number found at position", position, "and total comparisons are", comparisons)
                return
            position = (position + self.hashFunction2(name)) % self.size
            if position == initial_position:
                break
        
        print("Record not found.")
            
    def display(self):
        print("\nTelephone Book:")
        for i in range(self.size):
            if self.table[i]:
                print("Hash Value:", i, "Name:", self.table[i].get_name(), "Number:", self.table[i].get_number())
        print("The number of phonebook records in the Table are:", self.elementCount)

# Main code
def main():
    while True:
        print("************************")
        print("1. Linear Probing *")
        print("2. Double Hashing *")
        print("3. Exit *")
        print("************************")
        hash_choice = input("Enter Choice: ")

        if hash_choice == '1':
            size = int(input("Enter the size of hash table: "))
            telephone_book = HashTableLinearProbing(size)
        elif hash_choice == '2':
            size = int(input("Enter the size of hash table: "))
            telephone_book = HashTableDoubleHashing(size)
        elif hash_choice == '3':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")
            continue

        while True:
            print("************************")
            print("1. Insert *")
            print("2. Search *")
            print("3. Display *")
            print("4. Back *")
            print("************************")
            choice = input("Enter Choice: ")

            if choice == '1':
                name = input("Enter Name: ")
                number = int(input("Enter Number: "))
                record = Record(name, number)
                telephone_book.insert(record)
            elif choice == '2':
                name = input("Enter Name: ")
                telephone_book.search(name)
            elif choice == '3':
                telephone_book.display()
            elif choice == '4':
                print("Returning to hash selection menu...")
                break
            else:
                print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
