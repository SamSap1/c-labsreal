#include "edit_distance.h"
#include <algorithm>

int edit_distance(const std::string& p, const std::string& q){
const int maxlen = 25;

int d[maxlen + 1][maxlen + 1];

int pLength = p.size();
int qLength = q.size();


for (int i = 0; i <= pLength; ++i){
	d[i][0] = i;


}

for (int j = 0; j <= qLength; ++j){
d[0][j] = j;

}
for (int i = 1; i <= pLength; ++i) {
        for (int j = 1; j <= qLength; ++j) {
            int cost = (p[i - 1] == q[j - 1]) ? 0 : 1;
            d[i][j] = std::min({
                d[i - 1][j] + 1,      // Deletion
                d[i][j - 1] + 1,      // Insertion
                d[i - 1][j - 1] + cost // Substitution
            });
        }
    }

    return d[pLength][qLength];


}