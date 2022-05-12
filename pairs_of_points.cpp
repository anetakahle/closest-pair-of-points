#include <algorithm>
#include <iostream>
using namespace std;

struct vrchol{
    int x;
    int y;
    int idx;
    vrchol(){};
    vrchol(int a, int b, int idxx){
        x = a;
        y = b;
        idx = idxx;
    };
};

bool ma_mensiho(vrchol a, vrchol b){
    return a.x < b.x;
}
bool ma_mensiho_y(vrchol a, vrchol b){
    return a.y < b.y;
}

//promenne
vrchol min_dvojice[2];
long long minimum = 1ll<<62;
constexpr int velikost_prouzku = 130000;
vrchol k_porovnani[velikost_prouzku];

int vertices_counted = 0;
int zaplnene_v_k_porovnani = 0;

//nacitani vstupu
int main(){
    int xx;
    int yy;
    int delka;
    scanf("%d", &delka);
    vrchol seznam[delka]; //array
    for (size_t i = 0; i < delka; i++)
    {
        scanf("%d %d", &xx, &yy);
        vrchol zabka(xx, yy, i);
        seznam[i] = zabka;
    }

    sort(seznam, seznam+delka, ma_mensiho_y);

    while (vertices_counted < delka)//loop 1 a
    {
        int k_serazeni =zaplnene_v_k_porovnani;
        for (size_t i = zaplnene_v_k_porovnani; i < velikost_prouzku; i++) //loop 1 b
        {
            k_serazeni = i+1;
            if (vertices_counted < delka) //posledni prvek je na delka-1. indexu
            {
            k_porovnani[i] = seznam[vertices_counted];
            vertices_counted++;
            }
            else break;
        }

        
        sort(k_porovnani, k_porovnani+k_serazeni, ma_mensiho);
        // Porovnavani s minimem
        for (size_t i = 0; i < k_serazeni; i++)//loop 2
        {
            for (size_t j = i+1; j < k_serazeni; j++)//loop 3
            {
                long long rozdil_x_2 = (k_porovnani[j].x - k_porovnani[i].x);
                rozdil_x_2 *= rozdil_x_2;
                if (rozdil_x_2 < minimum) //pokud to je rovno, tak celkova vzdalenost bude bud stejna, nebo ne - tzn nemusime resit
                    {   
                        long long rozdil_y_2 = (k_porovnani[i].y -k_porovnani[j].y);
                        rozdil_y_2 *= rozdil_y_2;
                        if (rozdil_x_2 + rozdil_y_2 < minimum)
                        {
                            minimum = rozdil_x_2 + rozdil_y_2;
                            min_dvojice[0] = k_porovnani[i];
                            min_dvojice[1] = k_porovnani[j];
                        }
                        //if je vzdalenost bodu mensi nez min - aktualizuj min a min_dvojice};
                    }
                else break;
            }
            
        }
        
        zaplnene_v_k_porovnani = 0;  

        //konec = k_porovnani[50000]
        for (int i = k_serazeni-1; i >= 0; i--)
        {
            long long rozdil_y_2 = (k_porovnani[k_serazeni-1].y - k_porovnani[i].y);
            rozdil_y_2 *= rozdil_y_2;
            if (rozdil_y_2 >= minimum)
            {
                for (size_t j = i + 1; j < k_serazeni; j++)
                {
                    k_porovnani[zaplnene_v_k_porovnani] = k_porovnani[j];
                    zaplnene_v_k_porovnani++;
                }
                break;
            }
        }
    }    

    if (min_dvojice[0].idx < min_dvojice[1].idx)
        printf("%lld %d %d", minimum, min_dvojice[0].idx, min_dvojice[1].idx);
    else printf("%lld %d %d", minimum, min_dvojice[1].idx, min_dvojice[0].idx);
}


//konec, mame min











