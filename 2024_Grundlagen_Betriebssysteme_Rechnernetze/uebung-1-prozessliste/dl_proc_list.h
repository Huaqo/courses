Implementieren Sie eine Prozesstabelle mithilfe einer doppelt verketteten Liste.
Die Elemente der Liste entsprechen den vereinfachten Prozessleitblöcken. Für jeden Pro-
zess umfasst der zugehörige Leitblock die Prozess-ID (PID) und die ID des Elternprozesses
(parent PID, PPID).

Beachten Sie dabei:
• Geben Sie für die Funktionen der doppelt verketteten Liste im Fehlerfall negative
Werte und im Erfolgsfall 0 zurück. Falls der Rückgabetyp ein Pointer ist, soll die
Funktion im Fehlerfall NULL zurückgeben.


#ifndef dl_proc_list
#define dl_proc_list

#include <stddef.h>

typedef struct dl_proc_list {
    int PID;
    int PPID;
} dl_proc_list;

dl_proc_list* dl_proc_list_create()

int dl_proc_list_insert(dl_proc_list *list, int pid)

int dl_proc_list_get(dl_proc_list *list, int position, int* pid, int* ppid)

int dl_proc_list_remove(dl_proc_list *list, int pid)

void dl_proc_list_free(dl_proc_list *list)

#endif 