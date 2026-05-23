#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        char s[31], t[31];
        scanf("%s %s", s, t);
        
        int slen = strlen(s);
        int tlen = strlen(t);
        
        // Собираем индексы для каждой буквы в s
        int pos[26][30];
        int cnt[26] = {0};
        
        for (int i = 0; i < slen; i++) {
            int ch = s[i] - 'A';
            pos[ch][cnt[ch]++] = i;
        }
        
        // Идём по t с конца, берём последние доступные индексы
        int prev = -1;
        int ok = 1;
        
        for (int i = tlen - 1; i >= 0; i--) {
            int ch = t[i] - 'A';
            if (cnt[ch] == 0) {
                ok = 0;
                break;
            }
            
            int idx = pos[ch][--cnt[ch]];
            
            if (prev != -1 && idx >= prev) {
                ok = 0;
                break;
            }
            prev = idx;
        }
        
        printf("%s\n", ok ? "YES" : "NO");
    }
    
    return 0;
}