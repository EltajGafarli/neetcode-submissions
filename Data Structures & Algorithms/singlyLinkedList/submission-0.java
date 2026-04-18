class LinkedList {

    private final java.util.LinkedList<Integer> list;

    public LinkedList() {
        list = new java.util.LinkedList<>();
    }

    public int get(int index) {
        try {
            return list.get(index);
        } catch (Exception ex) {
            return -1;
        }
    }

    public void insertHead(int val) {
        list.addFirst(val);
    }

    public void insertTail(int val) {
        list.addLast(val);
    }

    public boolean remove(int index) {
        try {
            list.remove(index);
            return true;
        } catch (Exception ex) {
            return false;
        }
    }

    public ArrayList<Integer> getValues() {
        return new ArrayList<>(list);
    }
}