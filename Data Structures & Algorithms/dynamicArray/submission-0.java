public class DynamicArray {

    private int[] arr;
    private int capacity;
    private int size;


    public DynamicArray(int capacity) {
        this.arr = new int[capacity];
        this.capacity = capacity;
        this.size = 0;
    }

    public int get(int i) {
        return this.arr[i];
    }

    public void set(int i, int n) {
        this.arr[i] = n;
    }

    public void pushback(int n) {

        if (this.size < this.capacity) {
            this.arr[this.size] = n;
            this.size ++;
            return;
        }

        this.resize();

        this.arr[this.size] = n;
        this.size ++;
    }

    public int popback() {

        int end = this.arr[this.size - 1];

        this.size --;

        return end;
    }

    private void resize() {
        int[] newArr = new int[getCapacity() * 2];

        System.arraycopy(arr, 0, newArr, 0, this.getCapacity());

        this.arr = newArr;

        this.capacity *= 2;
    }

    public int getSize() {
        return this.size;
    }

    public int getCapacity() {
        return this.capacity;
    }
}