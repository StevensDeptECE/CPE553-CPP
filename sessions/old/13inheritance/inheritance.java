public class A {
  private int x;
	protected int y;
	public A()  { x = 0; }
}

public class B extends A { // inheritance in Java is all public

}

// interfaces can only have specification of functions (abstract methods)
public interface F {
  public void f(); // all children of F must write this
}

public abstract class AbstractClass implements F {
  private int x;
	public AbstractClass(int x) { this.x = x; }
}

public class MyClass extends AbstractClass {
  public void f() {
		System.out.println("I did it!");
	}
}
