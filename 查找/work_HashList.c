#include <stdio.h>

int main() {
    int m, p, key, count = 0;
    int hash[100];
    
    scanf("%d %d", &m, &p);
    for(int i = 0; i < m; i++) hash[i] = -1;
    
    while(1) {
        scanf("%d", &key);
        if(key == -1) break;
        
        int pos = key % p;
        int found = 0;
        
        while(1) {
            if(hash[pos] == key) {
                printf("%d\n", pos);
                found = 1;
                break;
            }
            
            if(hash[pos] == -1) {
                break;
            }
            
            pos = (pos + 1) % m;
        }
        
        if(found == 1) continue;
        
        if(count == m - 1) {
            printf("Table full\n");
            return 0;
        }
        
        int insert_pos = key % p;
        while(hash[insert_pos] != -1) {
            insert_pos = (insert_pos + 1) % m;
        }
        
        hash[insert_pos] = key;
        count++;
        printf("%d\n", insert_pos);
    }
    
    return 0;
}
