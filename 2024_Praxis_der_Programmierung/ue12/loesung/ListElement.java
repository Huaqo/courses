
/*
* class ListElement
*
*/

public class ListElement<T>{
	private T value;
	private ListElement<T> next;

	ListElement(T initValue){
		this.value = initValue;
		this.next = null;
	}

	ListElement(T initValue, ListElement<T> initNext){
		this.value = initValue;
		this.next = initNext;
	}

	public void setNext(ListElement<T> nextLe){
		next = nextLe;
	}

	public ListElement<T> getNext(){
		return this.next;
	}

	public void setValue(T newValue){
		value = newValue;
		
	}

	public T getValue(){
		return this.value;
	}

}
