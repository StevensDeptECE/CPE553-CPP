import java.util.*;

public class BuildList {
	public static void main(String[]args ) {
		final int n = 100000000;
		ArrayList<Integer> a = new ArrayList<>(n);
		for (int i = 0; i < n; i++)
			a.add(i); // new Integer(i);
		System.out.println(a.size());
	}
}
	
