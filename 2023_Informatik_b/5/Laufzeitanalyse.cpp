 
/*
(a) hat eine Zeitkomplexität von O(n), wobei n die Anzahl der Elemente in vec ist. 
Das liegt daran, dass jede Operation in der for-Schleife in konstanter Zeit ausgeführt wird 
und die Schleife genau n-Mal durchlaufen wird. 
*/

 int vector_summe(vector<int>& vec){ 
    int sum = 0;
    for (unsigned i =0; i < vec.size(); i++){
        sum +=vec[i];
    }
    return sum;
}

/*
(b) hat eine Zeitkomplexität von O(n^2), da es zwei verschachtelte Schleifen gibt, 
die jeweils bis zur Größe des Vektors laufen. 
Dies bedeutet, dass für jedes Element in vec alle Elemente innerhalb des Elementes einmal betrachtet werden, 
was zu n*n Operationen führt.
*/

vector<pair<int, int>> pairs(vector<int>& vec){ 
    vector<pair<int, int>> returnpairs;
    pair<int, int> p;
    for(unsigned i = 0; i<vec.size(); i++){
            for(unsigned j=0; j<vec.size(); j++){
                p = {vec[i], vec[j]};
                returnpairs.push_back(p);
        } 
    }
    return returnpairs;
}

/*
(c) Die Eingabegröße n ist die Größe von vec1 und m ist die Größe von vec2.  
Zuerst werden die separate Listen, vec1 und vec2, separat sortiert. 
Die Zeitkomplexität für das Sortieren von vec1 ist O(n log n) und O(m log m) für das Sortieren von vec2,
da das die Zeitkomplexität von mergesort ist.
Die anschließenden verschachtelten Schleifen, die über die beiden Vektoren iterieren, haben eine Zeitkomplexität von O(n*m), 
da jede Kombination aus Elementen von vec1 und vec2 einmal betrachtet wird.
Daher ist die gesamte Zeitkomplexität O(n log n + m log m + n*m). 
Die Anzahl der Operationen entspricht im Wesentlichen der Zeitkomplexität.
*/

vector<pair<int, int>> sorted_pairs(vector<int> vec1, vector<int> vec2){
    vector<pair<int, int>> returnpairs;
    pair<int, int> p;
    mergeSort(vec1);
    mergeSort(vec2);
    for(unsigned i = 0; i < vec1.size(); i++){
        for(unsigned j = 0; j < vec2.size(); j++){
            p = {vec1[i], vec2[j]};
            returnpairs.push_back(p);
        } 
    }
}






