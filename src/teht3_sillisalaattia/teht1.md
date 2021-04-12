# Tehtävä 1 vastaukset

C++11 oli merkittävä uusi C++ standardi. Selvitä (pintapuolisesti) seuraavien uusien ominaisuuksien merkitys:

 1. nullptr-avainsana
  - Avainsanaa tulee käyttää kun osoitin alustetaan nollaksi. Vanhastaan C:ssä pointteri alustettiin nollaksi asettamalla siihen nolla. Kuitenkin nolla on myös laillinen arvo kokonaislukutyyppiselle muuttujalle . Tämän epäselvyyden poistamiseksi C++11 -standardiin on lisätty nullptr -avainsana. Nullptr ei ole itsessään tyyppi, vaan avainsana, joka muunnetaan jokaiseksi pointer-tyypiksi aina tarpeen mukaan.
 
 2. auto-avainsana
  - auto-avainsanalla voidaan korvata muuttujan tyyppimäärittely tilanteissa, joissa kääntäjä jo muutenkin tietää tai pystyy päättelemään tyypin. Kätevä etenkin pitkissä tyyppirimpsuissa, esimerkiksi STL-säiliöitä käyttäessä.
 
 3. for-silmukan uusi syntaksi alkioiden läpikäymiseksi
  - Uusi syntaksi toimii näin:

        for(auto item : list) {
        
    Syntaksi mahdollistaa säiliön läpikäymisen ilman, että säiliön kokoa ja indeksointia tarvitsee miettiä. Tätä varten säiliön on toteutettava iteraattori-rajapinta.

 4. final- ja override –avainsanat (perintä, virtuaalifunktiot)
  - Override-avainsanalla voidaan osoittaa, että ollaan kirjoittamassa lapsiluokkaan metodia, jonka on tarkoitus ylikirjoittaa vanhempi-luokan virtuaalinen metodi. Näin kääntäjä tietää varoittaa mahdollisista virheistä, ja ikävät perintään liittyvät bugit voidaan välttää.
  - Final-avainsanalla taas voidaan estää metodin ylikirjoittaminen lapsiluokissa.
 5. =delete
  - delete-avainsanan avulla voidaan poistaa luokan konstruktori käytöstä, seuraavalla tavalla
  
        myClass(myClass cls) = delete

 6. long long int
  - long long int on vähintään 64-bittinen etumerkillinen kokonaisluku. C++-standardi määrittää minimin muuttujan koolle.

 7. hash-taulut: std::unordered_map (standardikirjasto)
  - standardikirjastoon on lisätty hajautustaulu. Hajautustaulu on tietorakenne, johon elementit tallennetaan avaimesta jollakin keinoin lasketun tarkistussumman avulla. Hajautustaulussa lisäykset, haut ja poistot ovat aikavaativuudeltaan vakio-operaatioita.
 
 8. säännölliset lausekkeet (std::regex)
  - Olen hieman järkyttynyt, ettei C++:n varhaisemmissa versioissa ollut säännöllisiä lausekkeita. Toisaalta aika monia C-kirjastoja kai edelleen käytetään. std::regex on siis kirjasto, jonka avulla voi luoda säännöllisiä lausekkeita, olioina. Kirjasto kääntää säännölliset lausekkeet olioiksi, ja tarjoaa myös oliot osumille sekä koko osumajoukolle.
