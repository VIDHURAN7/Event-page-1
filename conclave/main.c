#include<stdio.h>
#include<string.h>

struct InventoryItem {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addItem(struct InventoryItem items[], int *count);
void displayItems(struct InventoryItem items[], int count);
void updateItem(struct InventoryItem items[], int count);
void deleteItem(struct InventoryItem items[], int *count);
void searchItemById(struct InventoryItem items[], int count);

int main() {
    struct InventoryItem items[100]; 
    int count = 0;
    int choice;

    while(1) {
        // Menu
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Search Item by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                displayItems(items, count);
                break;
            case 3:
                updateItem(items, count);
                break;
            case 4:
                deleteItem(items, &count);
                break;
            case 5:
                searchItemById(items, count);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a new item to the inventory
void addItem(struct InventoryItem items[], int *count) {
    printf("Enter item ID: ");
    scanf("%d", &items[*count].id);
    printf("Enter item name: ");
    getchar();  // To consume the newline character left by scanf
    fgets(items[*count].name, sizeof(items[*count].name), stdin);
    items[*count].name[strcspn(items[*count].name, "\n")] = '\0';  // Remove newline
    printf("Enter item quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*count].price);
    (*count)++;  // Increment item count
    printf("Item added successfully.\n");
}

// Function to display all items in the inventory
void displayItems(struct InventoryItem items[], int count) {
    if(count == 0) {
        printf("No items in the inventory.\n");
        return;
    }
    printf("\nInventory List:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

// Function to update an existing item
void updateItem(struct InventoryItem items[], int count) {
    int id, found = 0;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(items[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            found = 1;
            printf("Item updated successfully.\n");
            break;
        }
    }

    if(!found) {
        printf("Item not found with ID %d.\n", id);
    }
}

// Function to delete an item by ID
void deleteItem(struct InventoryItem items[], int *count) {
    int id, found = 0;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < *count; i++) {
        if(items[i].id == id) {
            // Shift remaining items left
            for(int j = i; j < *count - 1; j++) {
                items[j] = items[j + 1];
            }
            (*count)--;  // Decrease item count
            found = 1;
            printf("Item deleted successfully.\n");
            break;
        }
    }

    if(!found) {
        printf("Item not found with ID %d.\n", id);
    }
}

// Function to search for an item by ID
void searchItemById(struct InventoryItem items[], int count) {
    int id, found = 0;
    printf("Enter the ID of the item to search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(items[i].id == id) {
            printf("\nItem Found:\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %.2f\n", items[i].price);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Item not found with ID %d.\n", id);
    }
}