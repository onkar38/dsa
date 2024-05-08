class KeyValuePair:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * self.size

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        if self.table[index] is None:
            self.table[index] = KeyValuePair(key, value)
        else:
            current = self.table[index]
            while current.next:
                current = current.next
            current.next = KeyValuePair(key, value)

    def find(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        while current:
            if current.key == key:
                return current.value
            current = current.next
        return None

    def delete(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        prev = None
        while current:
            if current.key == key:
                if prev:
                    prev.next = current.next
                else:
                    self.table[index] = current.next
                return
            prev = current
            current = current.next

    def display(self):
        for index, item in enumerate(self.table):
            print(f"Bucket {index}: ", end="")
            current = item
            while current:
                print(f"({current.key}: {current.value})", end=" -> " if current.next else "")
                current = current.next
            print("")

# Manual operations
def manual_operations(hash_table):
    while True:
        print("\n************************")
        print("1. Insert key-value pair")
        print("2. Find value by key")
        print("3. Delete key")
        print("4. Display hash table")
        print("5. Exit")
        print("************************")
        choice = input("Enter your choice: ")

        if choice == '1':
            key = input("Enter key: ")
            value = input("Enter value: ")
            hash_table.insert(key, value)
        elif choice == '2':
            key = input("Enter key to find value: ")
            value = hash_table.find(key)
            if value is not None:
                print(f"Value for key '{key}': {value}")
            else:
                print(f"Key '{key}' not found")
        elif choice == '3':
            key = input("Enter key to delete: ")
            hash_table.delete(key)
            print(f"Key '{key}' deleted")
        elif choice == '4':
            hash_table.display()
        elif choice == '5':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")

# Example usage:
if __name__ == "__main__":
    size = int(input("Enter the size of hash table: "))
    hash_table = HashTable(size)
    manual_operations(hash_table)
