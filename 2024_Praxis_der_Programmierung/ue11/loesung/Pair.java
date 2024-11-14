

public class Pair<T1, T2>{
	T1 first;
	T2 second;


	Pair(T1 first, T2 second){
		this.first = first;
		this.second = second;	
	}

	T1 getFirst(){
		return this.first;
	}


	T2 getSecond(){
		return this.second;
	}


}
