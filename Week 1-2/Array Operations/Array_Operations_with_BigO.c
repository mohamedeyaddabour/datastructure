#include <stdio.h>

// ================== TRAVERSAL — O(n) ==================
void traverse(int arr[], int n) {
    // Loop runs n times → O(n)
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}


// ================== INSERT END — O(1) ==================
void insertEnd(int arr[], int *n, int value) {
    // Just write at index n → constant time
    arr[*n] = value;   // O(1)
    (*n)++;            // O(1)
}


// ============= INSERT BEGINNING — O(n) ================
void insertBeginning(int arr[], int *n, int value) {
    // Shift all items right by 1
    // Loop runs n times → O(n)
    for (int i = *n; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = value;
    (*n)++;
}


// =============== INSERT AT POSITION — O(n) =============
int insertAt(int arr[], int *n, int pos, int value) {
    if (pos < 0 || pos > *n)
        return -1;

    // Shift elements → O(n)
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    (*n)++;
    return 0;
}


// =============== DELETE FROM END — O(1) =================
void deleteEnd(int *n) {
    // Just decrease size → O(1)
    if (*n > 0)
        (*n)--;
}


// ========== DELETE FROM BEGINNING — O(n) ===============
int deleteBeginning(int arr[], int *n) {
    if (*n == 0)
        return -1;

    // Shift everything left → O(n)
    for (int i = 0; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;
    return 0;
}


// ========== DELETE FROM POSITION — O(n) ================
int deleteAt(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n)
        return -1;

    // Shift elements → O(n)
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;
    return 0;
}


// =============== SEARCH (LINEAR) — O(n) ================
int search(int arr[], int n, int key) {
    // Check element by element → O(n)
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;

    return -1;
}


// ================== UPDATE — O(1) ======================
int update(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n)
        return -1;

    arr[pos] = value;  // Constant time → O(1)
    return 0;
}


// ================== MAIN (TEST) ========================
int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;

    traverse(arr, n);
    insertBeginning(arr, &n, 99);
    insertEnd(arr, &n, 77);
    insertAt(arr, &n, 3, 123);
    traverse(arr, n);

    deleteBeginning(arr, &n);
    deleteAt(arr, &n, 2);
    deleteEnd(&n);
    traverse(arr, n);

    printf("Search for 4 → index %d\n", search(arr, n, 4));

    update(arr, n, 0, 555);
    traverse(arr, n);

    return 0;
}
