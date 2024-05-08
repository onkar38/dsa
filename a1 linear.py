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
        while self.table[position]: position = (position + 1) % self.size
        self.table[position] = record
        self.elementCount += 1
        print("Phone number of", record.get_name(), "is at position", position)
        
    def search(self, name):
        position, comparisons = self.hashFunction(name), 0
        while self.table[position]:
            comparisons += 1
            if self.table[position].get_name() == name:
                print("Phone number found at position", position, "and total comparisons are", comparisons)
                return
            position = (position + 1) % self.size
        print("Record not found.")
            
    def display(self):
        print("\nTelephone Book:")
        for i in range(self.size):
            if self.table[i]: print("Hash Value:", i, "Name:", self.table[i].get_name(), "Number:", self.table[i].get_number())
        print("The number of phonebook records in the Table are:", self.elementCount)
# Main code
size = int(input("Enter the size of hash table: "))
telephone_book = HashTableLinearProbing(size)

while True:
    print("************************\n1. Insert *\n2. Search *\n3. Display *\n4. Exit *\n************************")
    choice = input("Enter Choice: ")
    if choice == '1': telephone_book.insert(Record(input("Enter Name: "), int(input("Enter Number: "))))
    elif choice == '2': telephone_book.search(input("Enter Name: "))
    elif choice == '3': telephone_book.display()
    elif choice == '4': print("Exiting..."); break
    else: print("Invalid choice. Please try again.")
