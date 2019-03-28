import java.util.ArrayList;
import java.util.List;

public class NestedList implements NestedInteger {

    private Integer a;
    private List<NestedInteger> e;

    public NestedList() {
        this.a = null;
        this.e = null;
    }

    public NestedList(Integer a) {
        this.a = a;
        this.e = null;
    }

    public NestedList(List<NestedInteger> e) {
        this.a = null;
        this.e = e;
    }

    @Override
    public boolean isInteger() {
        return this.a != null;
    }

    @Override
    public Integer getInteger() {
        return this.a;
    }

    @Override
    public List<NestedInteger> getList() {
        return this.e;
    }

    public static void main(String[] args) {

        List<NestedInteger> small = new ArrayList<>();
        small.add(new NestedList(1));
        small.add(new NestedList(1));

        List<NestedInteger> big = new ArrayList<>();
        big.add(new NestedList(small));
        big.add(new NestedList(2));
        big.add(new NestedList(small));

        NestedIterator nestedIterator = new NestedIterator(big);
        while (nestedIterator.hasNext()) {
            System.out.print(nestedIterator.next() + ", ");
        }
        System.out.println();
    }
}
