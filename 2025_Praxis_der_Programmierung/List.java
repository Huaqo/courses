public class List<T> {
	private ListElement<T> head;

	public void insert(ListElement<T> elem) {
		elem.next = head;
		head = elem;
	}

	public void insert(ListElement<T> newElem, int i) {
		if (i == 0)
			insert(newElem);
		else {
			ListElement<T> tmp = head;
			ListElement<T> prev = null;
			int l = 0;
			// Aufsuchen des i-ten Elements
			while (l < i) {
				prev = tmp;
				tmp = prev.next;
				l++;
			} // l == i ist erreicht
			prev.next = newElem;
			newElem.next = tmp;
		}
	}

	public boolean delete() {
		if (head == null) {
			return false;
		}
		head = head.next;
		return true;
	}

	public boolean isEmpty() {
		return head == null;
	}

	public int length() {
		int count = 0;
		ListElement<T> current = head;
		while (current != null) {
			count++;
			current = current.next;
		}
		return count;
	}

	public void show() {
		ListElement<T> current = head;
		if (current == null) {
			System.out.println("List is empty.");
			return;
		}
		System.out.print("List: ");
		while (current != null) {
			System.out.print(current.data + " -> ");
			current = current.next;
		}
		System.out.println("null");

	}
}
