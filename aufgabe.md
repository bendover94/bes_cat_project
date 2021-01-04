Die Projektidee "Cat Memory" ist in Ordnung. Da Sie eine 3er Gruppe sind,  fügen Sie folgende Anforderungen hinzu:
1. mehrere Spiele sollen parallel ablaufen können und die Anzahl soll jedem Spieler bei Spielbeginn angezeigt werden
2. es soll eine Maximalzeit geben, mit der auf eine Eingabeaufforderung reagiert werden muss, ansonsten wird automatisch eine passende Aktion durchgeführt (z.B. eine zufällige Karte wird ausgewählt)
3. am Spielende erfolgt die Ergebnisausgabe und es kann optional ein weiteres Spiel gestartet werden, ansonsten kann man sich abmelden oder wird nach einer Wartezeit automatisch abgemeldet
4. falsche Eingaben sollen abgefangen werden
5. ein Abbruch des Spiels soll jederzeit möglich sein
6. die Applikationen sollen wie folgt ausgeführt werden können:
    - uno_server [-p <port>]
    - uno_client [-i <server ip>] [-p <server port>]
    - Der Parameter für die -p-Option gibt den TCP-Port des Sockets an, über den kommuniziert werden soll. Der Server soll auf allen möglichen Schnittstellen/IPs lauschen. Beim Client soll zusätzlich mittels -i Parameter die IP-Adresse des Servers angeben werden können. Sollte dies fehlen, wird 127.0.0.1 verwendet. Wird kein Port übergeben, soll ein passender, vordefinierter Port verwendet werden, der in Server und Client gleich ist (z.B. die User-ID eines Autors). Sollten ungültige Parameter übergeben werden, soll zumindest eine usage message ausgegeben werden.
7. Der Server soll mit einem Signal beendet werden können. In diesem Fall soll der/die Client/s eine entsprechende Nachricht anzeigen und sich ebenfalls beenden. Beim Beenden sollen immer alle angelegten Ressourcen wieder frei geben werden.