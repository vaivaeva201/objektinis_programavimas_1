# Pirmas_Laboratorinis
# v1.0 versija


<h2>Naudojimosi instrukcija</h2>
<ol>
    <li>Susiinstaliuoti <a href="https://gnuwin32.sourceforge.net/packages/make.htm">MAKE</a></li>
    <li>Atsidaryti terminalą</li>
    <li>Klonuoti programos repozitoriją</li>

    git clone https://github.com/vaivaeva201/objektinis_programavimas_1

 <li>Terminale rašyti žemiau esančią komandą, norint paleisti pradinę programą
 <pre><code>make main</code></pre>
 Terminale rašyti žemiau esančią komandą, norint paleisti konteinerių testavimą
 <pre><code>make run0</code></pre></li>
 Terminale rašyti žemiau esančią komandą, norint paleisti 1 strategiją
 <pre><code>make run1</code></pre></li>
 Terminale rašyti žemiau esančią komandą, norint paleisti 2 strategiją
 <pre><code>make run2</code></pre></li>
  Terminale rašyti žemiau esančią komandą, norint paleisti 3 strategiją
 <pre><code>make run3</code></pre></li>
</ol>

# Kompiuterio charakteristikos

**Testuojamos sistemos parametrai**
| Parametras | Reikšmė |
| --------------------- | --------------------- |
| CPU | Apple M1, 8 core |
| RAM | 8 GB | 
| SSD | 256 GB |

# Pradinis tyrimas

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


# Pirma strategija

| Failo dydis | Konteinerio tipas | Bendras laikas|
| :--- | :--- | :--- |
| 1000 | Vektor | 0.0307956 s |
| 1000 | List | 0.0200887 s |
| 1000 | Deque | 0.0179197 s |
| 10 000 | Vektor | 0.198672 s |
| 10 000 | List | 0.178985 s |
| 10 000 | Deque | 0.178188 s |
| 100 000 | Vektor | 1.82792 s |
| 100 000 | List | 1.82841 s |
| 100 000 | Deque | 1.79769 s |
| 1 000 000 | Vektor | 19.156 s |
| 1 000 000 | List | 18.9481 s |
| 1 000 000 | Deque | 18.084 s |
| 10 000 000 | Vektor | 201.292 s |
| 10 000 000 | List | 218.99 s |
| 10 000 000 | Deque | 199.045 s |

# Antra strategija

| Failo dydis | Konteinerio tipas | Bendras laikas|
| :--- | :--- | :--- |
| 1000 | Vektor | 0.0330468 s |
| 1000 | List | 0.0200763 s |
| 1000 | Deque | 0.017967 s |
| 10 000 | Vektor | 0.196402 s |
| 10 000 | List | 0.177692 s |
| 10 000 | Deque | 0.183674 s |
| 100 000 | Vektor | 1.82267 s |
| 100 000 | List | 1.81831 s |
| 100 000 | Deque | 1.82855 s |
| 1 000 000 | Vektor | 19.0521 s |
| 1 000 000 | List | 18.8333 s |
| 1 000 000 | Deque | 18.4765 s |
| 10 000 000 | Vektor | 200.141 s |
| 10 000 000 | List | 214.759 s |
| 10 000 000 | Deque | 209.221 s |

# Trečia strategija

| Failo dydis | Konteinerio tipas | Bendras laikas|
| :--- | :--- | :--- |
| 1000 | Vektor | 0.0326659 s |
| 1000 | List | 0.0202716 s |
| 1000 | Deque | 0.0177419 s |
| 10 000 | Vektor | 0.196569 s |
| 10 000 | List | 0.177726 s |
| 10 000 | Deque | 0.188021 s |
| 100 000 | Vektor | 1.7905 s |
| 100 000 | List | 1.8126 s |
| 100 000 | Deque | 1.808661 s |
| 1 000 000 | Vektor | 18.7272 s |
| 1 000 000 | List | 19.1346 s |
| 1 000 000 | Deque | 18.536 s |
| 10 000 000 | Vektor | 194.153 s |
| 10 000 000 | List | 226.6 s |
| 10 000 000 | Deque | 200.114 s |