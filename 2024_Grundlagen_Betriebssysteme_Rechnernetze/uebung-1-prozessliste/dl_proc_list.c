// zum Erstellen der Liste, wobei die Liste zu Beginn einen Prozess mit PID = 1 und PPID = 0 enthalten soll
dl_proc_list* dl_proc_list_create() {
    dl_proc_list* proc_list = (dl_proc_list*) malloc(sizeof(dl_proc_list));
    if (proc_list == NULL) {
        return NULL;
    }
    proc_list->PID = 1;
    proc_list->PPID = 0;
}

// zum Einfügen eines Prozesses mit PID pid in die Liste, unter den folgenden Bedingungen:
// – Die Liste ist stets aufsteigend sortiert,
// – jede Prozess-ID kommt höchstens einmal vor und
// – als neuer Elternprozess wird der Prozess mit der bisher höchsten Prozess-ID festgelegt.
int dl_proc_list_insert(dl_proc_list *list, int pid){

}

// zum Abfragen der PID und PPID des Prozesses an der gegebenen Position in der Liste und Abspeichern der erhaltenen Werte in den Parametern pid und ppid,
int dl_proc_list_get(dl_proc_list *list, int position, int* pid, int* ppid){

}

// zum Entfernen des Prozesses p mit der PID pid aus der Liste, unter den folgenden Bedingungen:
// – Das Löschen des Prozesses mit PID = 1 soll verhindert werden und
// – die Kindprozesse des zu löschenden Prozesses p erhalten den Elternprozess von p als neuen Elternprozess.
int dl_proc_list_remove(dl_proc_list *list, int pid){

}

// zum Freigeben des allokierten Speichers.
void dl_proc_list_free(dl_proc_list *list){
    
}