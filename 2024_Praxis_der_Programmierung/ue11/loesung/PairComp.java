
import java.util.*;


public class PairComp<T1 extends Number, T2 extends Number> implements Comparable<PairComp<T1,T2>> {
	T1 first;
	T2 second;


	PairComp(T1 first, T2 second){
		this.first = first;
		this.second = second;	
	}

	T1 getFirst(){
		return this.first;
	}


	T2 getSecond(){
		return this.second;
	}
	
	@Override
	public int compareTo(PairComp<T1,T2> other){
		if (this.getFirst().doubleValue() < other.getFirst().doubleValue()){
			return -1;
		}
		if (this.getFirst().doubleValue() > other.getFirst().doubleValue()){
			return 1;
		}
		return 0;
		
	}

}
