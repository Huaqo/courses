

public class List<T>{
	private ListElement<T> head; 

	public List(ListElement<T> initLe){
		head = initLe;
	}

	
	public void insert(ListElement<T> newLe){
		newLe.setNext(head);
		this.head = newLe;
	}

	
	public boolean delete(){
		if (this.isEmpty()){
			return false;
		}
		else {
			this.head = head.getNext();
			return true;
		}
	}


	public boolean isEmpty(){
		if (head == null){
			return true;
		}
		else{
			return false;
		}
	}

	public int length(){
		int count = 0;
		
		ListElement<T> curr = head;
		while (curr != null){
			count += 1;
			curr = curr.getNext();
		}
		return count;
	}

	
	public void show(){
		ListElement<T> curr = head;
		while (curr != null){
			if (curr.getNext() == null){	
				System.out.println(""+ curr.getValue());
				}
			else {
				System.out.print(curr.getValue() + ", ");
			}
			curr = curr.getNext();
		}
	}


	public boolean insertIndex(ListElement<T> newElem, int i) {	
	  if (i == 0){
		insert(newElem);
		return true;
	  }
	  else {
		ListElement<T> tmp = head;
		ListElement<T> prev = null;
		int l = 0;
		// Aufsuchen des i-ten Elements
		while (l < i) {
		  prev = tmp;
		  tmp = prev.getNext();
		  l++;
		  if (l > length()){
			return false;
		  }
		} // l == i ist erreicht
		prev.setNext(newElem);
		newElem.setNext(tmp);
		return true;
    }
}


}
