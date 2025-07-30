/*
 * Name: Joaquin Gottlebe
 * Matrikelnummer: 829101
 */

import java.util.List;
import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.HashSet;
import java.util.Set;

/**
 * A graph node that can store a tag, info,
 * and connections to neighboring nodes.
 */
public class Node<T, I> implements Taggable<T> {

	// Private member variables
	private T tag;
	private I info;
	private List<Node<T, I>> neighbors;

	// Constructor
	public Node(T tag, I info) {
		this.tag = tag;
		this.info = info;
		this.neighbors = new ArrayList<>();
	}

	// Set tag.
	@Override
	public void setTag(T tag) {
		this.tag = tag;
	}

	// Get tag.
	public T getTag() {
		return tag;
	}

	// Get info.
	public I getInfo() {
		return info;
	}

	// Set info.
	public void setInfo(I info) {
		this.info = info;
	}

	// Get neighbors.
	public List<Node<T, I>> getNeighbors() {
		return neighbors;
	}

	// Connects this node to another node.
	public void connect(Node<T, I> other) {
		if (!neighbors.contains(other)) {
			neighbors.add(other);
			other.connect(this);
		}
	}

	// Disconnects this node from another node.
	public void disconnect(Node<T, I> other) {
		if (neighbors.contains(other)) {
			neighbors.remove(other);
			other.disconnect(this);
		}
	}

	// Breadth-first traversal of the network starting from this node. Returns nodes
	// in a list.
	public List<Node<T, I>> traverse() {
		List<Node<T, I>> visitedOrder = new ArrayList<>();
		Set<Node<T, I>> visited = new HashSet<>();
		Queue<Node<T, I>> queue = new LinkedList<>();

		queue.add(this);
		visited.add(this);

		while (!queue.isEmpty()) {
			Node<T, I> current = queue.poll();
			visitedOrder.add(current);

			for (Node<T, I> neighbor : current.getNeighbors()) {
				if (!visited.contains(neighbor)) {
					queue.add(neighbor);
					visited.add(neighbor);
				}
			}
		}

		return visitedOrder;
	}

	// Prints this nodes tag and info.
	public void printNode() {
		System.out.println("Node: " + tag + ", Info: " + info);
		System.out.println();
	}

	// Prints neighbours of this node.
	public void printNeighbors() {
		System.out.print("Neighbors of " + tag + ": ");
		if (neighbors.isEmpty()) {
			System.out.println("no neighbors\n");
		} else {
			for (Node<T, I> neighbor : neighbors) {
				System.out.print(neighbor.getTag() + " ");
			}
			System.out.println('\n');
		}

	}

	// Uses traverse() to print the network of this node. Avoids edge duplications.
	public void printNetwork() {
		List<Node<T, I>> networkNodes = traverse();
		Set<String> printedEdges = new HashSet<>();

		for (Node<T, I> node : networkNodes) {
			for (Node<T, I> neighbor : node.getNeighbors()) {

				// Canonicalize edge to avoid duplicates
				String canonicalEdge = node.getTag().toString().compareTo(neighbor.getTag().toString()) <= 0
						? node.getTag().toString() + "-" + neighbor.getTag().toString()
						: neighbor.getTag().toString() + "-" + node.getTag().toString();

				if (!printedEdges.contains(canonicalEdge)) {
					System.out.println(
							node.getTag().toString() + node.getInfo().toString() +
									" - " +
									neighbor.getTag().toString() + neighbor.getInfo().toString());
					printedEdges.add(canonicalEdge);
				}

			}
		}
		System.out.println();
	}
}
