// basic time O(n^2) solution
bool has_duplicates00(a, n)
{
    for (each element a[i]) {
        for (each element a[j] from i+1 to end of array) {
            if (array[i] == a[j]) {
                return true
            }
        }
    }
    return false
}

// O(n) time, O(n^2) space using "seen" table
bool has_duplicates01(a, n)
{
    allocate "seen" table
    for (each element in a) {
        if (it has already been seen in table) {
            return true
        }
    }
    return false
}
