import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class NestedIterator implements Iterator<Integer> {

    Deque<NestedInteger> queue;

    public NestedIterator(List<NestedInteger> list) {

        queue = new LinkedList<>();
        nestedIterator(list);
    }

    private void nestedIterator(List<NestedInteger> list) {
        for (NestedInteger item: list) {
            if (item.isInteger()) {
                queue.offer(item);
            }
            else {
                nestedIterator(item.getList());
            }
        }
    }

    @Override
    public Integer next() {
        return queue.poll().getInteger();
    }

    @Override
    public boolean hasNext() {
        return !queue.isEmpty();
    }
}
