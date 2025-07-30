/*
 * Name: Joaquin Gottlebe
 * Matrikelnummer: 829101
 */

import java.util.Arrays;
import java.util.List;

// Test class to test Node and Taggable class
public class Test {
	public static void main(String[] args) {

		// Create nodes with String tags and List<Integer> info
		Node<String, List<Integer>> A = new Node<>("A", Arrays.asList(1, 2, 3));
		Node<String, List<Integer>> B = new Node<>("B", Arrays.asList(4, 5, 6));
		Node<String, List<Integer>> C = new Node<>("C", Arrays.asList(7, 8, 9));
		Node<String, List<Integer>> D = new Node<>("D", Arrays.asList(10, 11, 12));
		Node<String, List<Integer>> E = new Node<>("E", Arrays.asList(13, 14, 15));
		Node<String, List<Integer>> F = new Node<>("F", Arrays.asList(16, 17, 18));
		Node<String, List<Integer>> G = new Node<>("G", Arrays.asList(19, 20, 21));

		// Print node
		A.printNode();

		// Build connections between nodes
		A.connect(F);
		A.connect(G);
		G.connect(F);
		G.connect(B);
		F.connect(B);
		F.connect(C);
		C.connect(D);
		D.connect(E);

		// Print neighbors
		A.printNeighbors();

		// Print network
		System.out.println("Graph 1:");
		A.printNetwork();

		// Change network
		A.setTag("A2");
		B.setTag("B2");
		G.setTag("G2");
		A.setInfo(Arrays.asList(23, 24, 25));
		B.setInfo(Arrays.asList(5, 6));
		G.setInfo(Arrays.asList(19, 20, 21, 22));
		A.connect(B);
		B.connect(D);
		C.connect(E);
		G.disconnect(F);
		F.disconnect(C);
		C.disconnect(D);

		// Print network
		System.out.println("Graph 2:");
		A.printNetwork();
	}
}
