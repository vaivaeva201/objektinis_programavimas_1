# Pirmas_Laboratorinis
# v1.0 versija

# Kompiuterio charakteristikos

**Testuojamos sistemos parametrai**
| Parametras | Reikšmė |
| --------------------- | --------------------- |
| CPU | Apple M1, 8 core |
| RAM | 8 GB | 
| SSD | 256 GB |

**Pradinis konteinerių tyrimas**
| Failo dydis | Konteinerio tipas | Failų nuskaitymas | Rikiavimas | Skirstymas | Bendras laikas|
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1000 | Vektor | 0.0204036 s | 0.000716361 s | 0.000484708 s | 0.0216047 s |
| 1000 | List | 0.0166401 s | 0.000375708 s | 0.00493514 s | 0.0175093 s|
| 1000 | Deque | 0.0167215 s | 0.000772055 s | 0.0003275 s | 0.0178211 s |

| 10 000 | Vektor | 0.171425 s | 0.00527711 s | 0.00424914 s | 0.180951 s |
| 10 000 | List | 0.168373 s | 0.00484165 s | 0.00575678 s | 0.178971 s |
| 10 000 | Deque | 0.169198 s | 0.00607807 s | 0.00328203 s | 0.178558 s |

| 100 000 | Vektor | 1.76493 s | 0.0497434 s | 0.0478277 s | 1.8625 s |
| 100 000 | List | 1.76663 s | 0.0621462 s | 0.0740567 s | 1.90283 s |
| 100 000 | Deque | 1.76964 s | 0.0557336 s | 0.0372298 s | 1.86261 s |

| 1 000 000 | Vektor | 17.9692 s | 0.505193 s | 0.682439 s | 19.1568 s |
| 1 000 000 | List | 17.7371 s | 1.18292 s | 1.27002 s | 20.19 s |
| 1 000 000 | Deque | 17.6705 s | 0.552359 s | 0.510158 s | 18.733 s |

| 10 000 000 | Vektor | 191.887 s | 5.12481 s | 10.1508 s | 207.733 s |
| 10 000 000 | List | 192.436 s | 21.5431 s | 35.7543 s | 249.733 s |
| 10 000 000 | Deque | 191.484 s | 5.788 s | 7.82104 s | 205.093 s |


