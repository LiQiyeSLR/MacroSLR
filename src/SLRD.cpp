#include "SLRD.h"

SLRD::SLRD() {
    C.x = C.y = Cevent.y = Cevent.x = Cbusy.x = Cbusy.y = 0;
    MAIL = FRIENDS = HELL = ICEFIRE = BAG = HERB = RACE = THEATER = MYSTERY = XIAOWU = TRIAL = TASKS = TREANT = ABYSS = ENERGY = PAGODA = TYRANT = ELEMENT = TOURNAMENT = false;
    dimX = 0;
    dimY = 0;
    endmacro = false;
    restartMacro = true;
    waitMacro = false;

}

SLRD::SLRD(int SizeX,int SizeY) {
    C.x = C.y =Cevent.y=Cevent.x=Cbusy.x=Cbusy.y=0;
    MAIL = FRIENDS = HELL= ICEFIRE= BAG= HERB= RACE= THEATER= MYSTERY= XIAOWU= TRIAL = TASKS= TREANT= ABYSS= ENERGY = PAGODA = TYRANT= ELEMENT= TOURNAMENT = false;
    dimX = SizeX;
    dimY = SizeY;
    endmacro = false;
    restartMacro=true;
    waitMacro=false;
}
void SLRD::setOrder() {
    for (int i = 0; i < 20; i++) {
        Order[i] = i;
    }
}


void SLRD::selectActivity() {
    string choix;
    bool leave = false;
    cout << "Type which activity you wanna do:" << endl;
    cout << "ALL : 0"<<endl;
    cout << " MAIL:A ; FRIENDS:B ; HELL:C ; ICEFIRE:D ; BAG:E ; HERB:F ; RACE:G ; THEATER:H ; MYSTERY:I ; XIAOWU:J  ; TASKS:K ; TREANT:L ; TYRANT:M ; ELEMENT:N"<<endl;
    cout << "for example: abjdlm or ABJghDd or 0"<<endl;
    cin >> choix;
    for (int i = 0; i < choix.size() && leave == false; i++) {
        switch (tolower(choix[i])) {
        case 'a':
            MAIL = true;
            cout << "MAIL, ";
            break;
        case 'b':
            FRIENDS = true;
            cout << "FRIENDS, ";
            break;
        case 'c':
            HELL = true;
            cout << "HELL, ";
            break;
        case 'd':
            ICEFIRE = true;
            cout << "ICEFIRE, ";
            break;
        case 'e':
            BAG = true;
            cout << "BAG, ";
            break;
        case 'f':
            HERB = true;
            cout << "HERB, ";
            break;
        case 'g':
            RACE = true;
            cout << "RACE, ";
            break;
        case 'h':
            THEATER = true;
            cout << "THEATER, ";
            break;
        case 'i':
            MYSTERY = true;
            cout << "MYSTERY, ";
            break;
        case 'j':
            XIAOWU = true;
            cout << "XIAOWU, ";
            break;
        case 'k':
            TASKS = true;
            cout << "TASKS, ";
            break;
        case 'l':
            TREANT = true;
            cout << "TREANT, ";
            break;
        case 'm':
            TYRANT = true;
            cout << "TYRANT, ";
            break;
        case 'n':
            ELEMENT = true;
            cout << "ELEMENT, ";
            break;
        case '0':
            MAIL = FRIENDS = HELL = ICEFIRE = BAG = HERB = RACE = THEATER = MYSTERY = XIAOWU = TASKS = TREANT = TYRANT = ELEMENT = true;
            cout << "MAIL, FRIENDS, HELL, ICEFIRE, BAG, HERB, RACE, THEATER, MYSTERY, XIAOWU, TASKS, TREANT, TYRANT, ELEMENT ";
            leave = true;
            break;
        }
    
    }
    cout << " will be done.";

}



bool SLRD::macroEnd() {
    if (FRIENDS == false && MAIL == false && HELL == false && ICEFIRE == false && DISPATCH == false && TOURNAMENT == false && BAG == false && HERB == false && RACE == false && THEATER == false && MYSTERY == false && PAGODA == false && XIAOWU == false && ENERGY == false && TASKS == false && ABYSS == false && TYRANT == false && ELEMENT == false && TREANT == false) {
        endmacro = true;
        return true;
    }
    else return false;
}

void SLRD::macroLoop() {
  
    while (true) {
        switch (restartMacro) {
        case true:
            startSLRD();
            //restartMacro = false;
            break;
        case false:
            if (HELL) {
                doHell();
                HELL = false;
                break;
            }
            if (ICEFIRE) {
                doIcefire();
                ICEFIRE = false;
                break;
            }
            if (MAIL) {
                doMail();
                MAIL = false;
                break;
            }
            if (FRIENDS) {
                doFriends();
                FRIENDS = false;
                break;
            }
            if (BAG) {
                getBag();
                BAG = false;
                break;
            }
            if (THEATER) {
                doTheater();
                THEATER = false;
                break;
            }
            if (MYSTERY) {
                doMystery();
                MYSTERY = false;
                break;
            }
            if (XIAOWU) {
                doXiao();
                XIAOWU = false;
                break;
            }
            if (HERB) {
                doHerb();
                HERB = false;
                break;
            }
            if (RACE) {
                doRace();
                RACE = false;
                break;
            }
            if (TASKS) {
                doTasks();
                TASKS = false;
                break;
            }
            if (TOURNAMENT) {
                doTournament();
                TOURNAMENT = false;
                break;
            }


            if (PAGODA) {

                break;
            }

            if (ENERGY) {

                break;
            }

            if (ABYSS) {

                break;
            }
            if (TYRANT) {
                doTyrant();
                TYRANT = false;
                break;
            }
            if (ELEMENT) {
                doElement();
                ELEMENT = false;
                break;
            }
            if (TREANT) {
                doTreant();
                TREANT = false;
                break;
            }
            if (TRIAL) {
                doTrial();
                TRIAL = false;
                break;
            }
        } 
        if (macroEnd()) {
            std::cout << "trouv�!" << std::endl;
            break;
        }
    }
}


void SLRD::recursiveSearch(const std::filesystem::path& dirPath, std::vector<std::string>& focus)
{ 
    for (const auto& entry : std::filesystem::directory_iterator(dirPath))
    {
        if (std::filesystem::is_directory(entry.status()))
        {
            // Call recursiveSearch function for subdirectory
            recursiveSearch(entry.path(), focus);
        }
        else
        {
            // Check if the file extension is ".png"
            if (entry.path().extension() == ".png")
            {
                // Add the file path with name and extension to the focus vector
                focus.push_back(entry.path().string());
            }
        }
    }
}

void SLRD::startSLRD() {
    try {
        std::cout << "RESTART";
        restartMacro = false;
        rebootCount = 0;
        adb.quit(PSLR);
        adb.launch(SLR);
        adb.wait(3000);
        while (!findclick(croixmenu));
        while (findclick(croixmenu));
        while (!findclick(iconSLR));
        while (findclick(iconSLR));
        goHome();
        
    }
    catch (int e) {
        
        return;
    }
}
void SLRD::goHome() {
    try {
        while (findclick(back));
        while (!find(pass)) {
            adb.touch(dimX * 0.96, dimY * 0.15);
            adb.wait(200);
        }
    }
    catch (int e) {
        std::cout << "error";
        return;
    }
}

void SLRD::doMystery() {
    try {
        goHome();
        while (!findclick(mysterychest));
        for (int i = 0; i < 6; ++i) {
            while (!findclick(watchadmystery));
            while (findclick(watchadmystery));
            while (!find(adwatched));
            while (!sys.StringInLogcat("ads_play_complete")) {
                rebootCount++;
            }
            adb.back();
            while (!findclick(congrats));
            while (findclick(congrats));
        }
        MYSTERY = false;
        while (!findclick(croixmenu));
        while (findclick(croixmenu));
        goHome();
    }
    catch (int e) {
        return;
    }
}

void SLRD::doTreant() {
    try{
        goHome();
        while (!findclick(treant)) {
            swiperightmenu();
        }
        while (findclick(treant));
        while (!findclick(icontreant)) {
            if (findclick(icontreantlight))break;
        }
        if (getDay() != 1) {
                while (!findclick(fighttreant));
                while (findclick(fighttreant));
                while (!findclick(sweeptreant));
                while (findclick(sweeptreant));
                while (!findclick(confirm));
               while (findclick(confirm));
                while (!findclick(fighttreant));
                while (findclick(fighttreant));
                while (!findclick(sweeptreant));
                while (findclick(sweeptreant));
                while (!findclick(confirm));
                while (findclick(confirm));
        }
        else {
            while (!findclick(fighttreant));
            while (findclick(fighttreant));
            while (!findclick(battle));
            while (findclick(battle));
            while (!findclick(fightingtreant));
            while (findclick(fightingtreant));
            while (!findclick(confirmendbattle));
            while (findclick(confirmendbattle));
            while (!findclick(fighttreant));
            while (findclick(fighttreant));
            while (!findclick(sweeptreant));
           while (findclick(sweeptreant));
            while (!findclick(confirm));
            while (findclick(confirm));
        }
        while (!findclick(pointstreant));
        while (findclick(pointstreant))
        while (!findclick(claimalltreant));
        while (findclick(claimalltreant));
        while (!findclick(congrats));
        while (findclick(congrats));
        while (!findclick(croixmenu));
        while (findclick(croixmenu));
        TREANT = false;
        goHome();
    }
    catch (int e) {
        return;
    }
}
void SLRD::doElement() {
    try {
        goHome();
        while (!findclick(treant)) {
            swiperightmenu();
        }
        while (findclick(treant));
        while (!findclick(iconelement)) {
            if (findclick(iconelementlight))break;
        }
        if (getDay() != 1) {
            while (!findclick(fightelement));
            while (findclick(fightelement));
            while (!findclick(sweeptreant));
            while (findclick(sweeptreant));
            while (!findclick(confirm));
            while (findclick(confirm));
            while (!findclick(fightelement));
            while (findclick(fightelement));
            while (!findclick(sweeptreant));
            while (findclick(sweeptreant));
            while (!findclick(confirm));
            while (findclick(confirm));
        }
        else {
            while (!findclick(fightelement));
            while (findclick(fightelement));
            while (!findclick(battle));
            while (findclick(battle));
            while (!findclick(fightingelement));
            while (findclick(fightingelement));
            while (!findclick(confirmendbattle));
            while (findclick(confirmendbattle));
            while (!findclick(fightelement));
            while (findclick(fightelement));
            while (!findclick(sweeptreant));
            while (findclick(sweeptreant));
            while (!findclick(confirm));
            while (findclick(confirm));
        }
        while (!findclick(pointstreant));
        while (findclick(pointstreant))
            while (!findclick(claimalltreant));
        while (findclick(claimalltreant));
        while (!findclick(congrats));
        while (findclick(congrats));
        while (!findclick(croixmenu));
        while (findclick(croixmenu));
        ELEMENT = false;
        goHome();
    }
    catch(int e){
        return;
    }
}


void SLRD::doRace() {
    try {
        int day = getDay();
        goHome();
        if (day != 6 && day != 7) {
            while (!findclick(pot)) {
                swiperightmenu();
            }
            while (!findclick(racechoose));
            while (findclick(claimrace));
        }
        RACE = false;
        goHome();
    }
    catch (int e) {
        return;
    }
}

void SLRD::doDispatch() {
    try {
        goHome();
        swipemiddlemenu();
        while (!findclick(sect));
        while (!findclick(dispatchbuilding)) {
            adb.swipe(dimX / 10, dimY / 2, 9*dimX / 10, dimY / 2, 500);
        }
        while (!findclick(claimdispatch));
        adb.wait(2000);
        while (findclick(congrats)) {
            adb.wait(2000);
        }
        adb.wait(2000);
        while (findclick(dispatch)) {
            adb.wait(2000);
           while(!findclick(deploy));
            adb.wait(2000);
           while(!findclick(dispatch)); 
           adb.wait(2000);
        }
        DISPATCH = false;
        while (!findclick(croixmenu));
        goHome();
    }
    catch (int e) {
        return;
    }
}

void SLRD::doHerb() {
    try {
        goHome();
        while (!findclick(pot)) {
            swiperightmenu();
        }
        while (findclick(pot));
        while (!findclick(potchoose));
        while (findclick(potchoose));
        adb.wait(5000);
        while (findclick(claimallpot)) {
            while (!findclick(congrats));
            while (!findclick(croixmenu));
        }
        while (!findclick(protect));
        while (findclick(protect));
        while (!findclick(confirmpot));
        while (findclick(confirmpot));
        while (!findclick(deliver));
        while (findclick(deliver));
        int day = getDay();
        if (day == 6 || day == 7) {
            while (!findclick(shipnow));
            while (!findclick(confirmdeliver));
        }
        else {
            while (!findclick(godlyrefresh));
            while (!findclick(confirm));
            while (!findclick(shipnow));
            adb.wait(1000);
            while (findclick(buy)) {
                while (!findclick(croixmenu));
                while (!findclick(shipnow));
            }
        }
        HERB = false;
        goHome();
    }
    catch (int e) {  
        return;
    }
}



void SLRD::doHell() {// � revoir quick challenge
    try {
        goHome();
        while (!findclick(hell)) {
            adb.swipe(9 * dimX / 10, dimY / 2, dimX / 10, dimY / 2, 500);
        }
        adb.wait(3000);
        while (findclick(claimrace) || findclick(congrats));
        adb.wait(2000);
        if (find(advance) || find(oneclicknotavailable)) {
            HELL = false;
            goHome();
            return;
        }     
        while (!findclick(oneclickhell));
        while (!findclick(confirm));
        while (findclick(confirm));
        while (!findclick(battle));
        while (findclick(battle));
        while (!findclick(endofchallengehell));
        while (findclick(endofchallengehell));
        HELL = false;
        goHome();
    }
    catch (int e) {       
        return;
    }
}


void SLRD::doMail() {
    try {
        goHome();
        while (!findclick(mail));
        while (findclick(mail));
        while (!findclick(claimall));
        adb.wait(2000);
        while (findclick(congrats));
        MAIL = false;
        goHome();
    }
    catch (int e) {       
        return;
    }
}

void SLRD::doTheater() {
    try {
        goHome();
        while (!findclick(store));
        while (!findclick(theaterchoose));
        while (findclick(theaterchoose));
        for (int i = 0; i < 10; i++) {
            while (!findclick(watchtheater));
            while (findclick(watchtheater));
            while (!sys.StringInLogcat("ads_play_complete")) {
                rebootCount++;
            }
            adb.back();
            adb.wait(2000);
        }
        adb.wait(1000);
        adb.touch(dimX * 0.36, dimY*0.351);
        adb.wait(1000);
        findclick(max);
        adb.wait(1000);
        findclick(confirmpurchase);
        adb.wait(1000);
        findclick(congrats);
        adb.wait(1000);
        adb.touch(dimX * 0.57, dimY * 0.351);
        adb.wait(1000);
        findclick(max);
        adb.wait(1000);
        findclick(confirmpurchase);
        adb.wait(1000);
        findclick(congrats);
        adb.wait(1000);
        adb.touch(dimX * 0.78, dimY * 0.351);
        adb.wait(1000);
        findclick(max);
        adb.wait(1000);
        findclick(confirmpurchase);
        adb.wait(1000);
        findclick(congrats);
        THEATER = false;
        goHome();
    }
    catch (int e) {       
        return;
    }
}

void SLRD::doTrial() {
    try {
        goHome();
        while (!findclick(beast)) {
            adb.swipe(9 * dimX / 10, dimY / 2, dimX / 10, dimY / 2, 500);
        }
        while (!findclick(gianttrial));
        adb.wait(3000);
        while (findclick(canexplore)) {
            adb.wait(3500);
            if (findclick(beast10k)||findclick(beast5k)) {
                adb.wait(3000);
                while (findclick(battle));
                while (findclick(congrats));
            }
        }
        TRIAL = false;
        goHome();
    }
    catch (int e) {
        return;
    }

}

void SLRD::doIcefire() {
    try {
        goHome();
        while (!findclick(icefire)) {
            adb.swipe(9 * dimX / 10, dimY / 2, dimX / 10, dimY / 2, 500);
        }
        while (findclick(icefire));
        while (!findclick(oneclickroll));
        while (findclick(oneclickroll));
        while (!findclick(start));
        while (findclick(start));
        while (!findclick(manageherbs));
        while (findclick(manageherbs));
        adb.wait(2000);
        for (int i = 0; i < 5; ++i) {
            if (getArray(collection)) {
                selectRangeCoords(listcoords, 0, gauche);
                adb.touch(C.x, C.y);
                adb.touch(C.x, C.y);
                adb.wait(1000);
                adb.swipe(6 * dimX / 10, dimY / 2, 3.65 * dimX / 10, dimY / 2, 1000);
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (getArray(collection)) {
                selectRangeCoords(listcoords, i, gauche);
                adb.touch(C.x, C.y);
                adb.touch(C.x, C.y);
                adb.wait(1000);
                adb.swipe(6 * dimX / 10, dimY / 2, 3.65 * dimX / 10, dimY / 2, 1000);
            }
        }
        adb.wait(1000);
        while(!findclick(croixmenu));
        while (findclick(croixmenu));
        while (!find(endicefire));
        ICEFIRE = false;
        goHome();
    }
    catch (int e) {       
        return;
    }
}
void SLRD::doFriends() {
    try {
        goHome();
        while (!findclick(friends));
        adb.wait(1000);
        while (!findclick(sendall));
        while (!findclick(claimallfriends));
        FRIENDS = false;
        goHome();
    }
    catch (int e) {     
        return;
    }
}
void SLRD::doTasks() {
    try {
        goHome();
        while (!findclick(tasks));
        if (find(claimtask)) {
            while (!findclick(claimallfriends));
            while (!findclick(congrats));
            while (findclick(congrats));
        }
        while (!findclick(weekly));
        if (find(claimtask)) {
            while (!findclick(claimallfriends));
            while (!findclick(congrats));
            while (findclick(congrats));
        }
        TASKS = false;
        goHome();
    }
    catch (int e) {     
        return;
    }
}

void SLRD::doShop() {
    try {
        goHome();
        swipemiddlemenu();
        while (findclick(shop));
    }
    catch (int e) {        
        return;
    }
}
void SLRD::doXiao() {
    try {
        goHome();
        while (!findclick(xiaoassistant));
        adb.wait(1000);
        while(!findclick(completeall));
        while (findclick(completeall));
        while (!findclick(confirmxiao));
        while (findclick(confirmxiao));
        while (!findclick(gameplay));
        while (!findclick(completeall));
        while (findclick(completeall));
        while (!findclick(confirmxiao));
        while (findclick(confirmxiao));
        while (!findclick(cancel));
        while (findclick(cancel));
        while (!findclick(rankingxiao));
        while (!findclick(completeall));
        while (findclick(completeall));
        while (!findclick(confirmxiao));
        while (findclick(confirmxiao));
        while (!findclick(sectxiao));
        while (!findclick(completeall));
        while (findclick(completeall));
        while (!findclick(confirmxiao));
        while (findclick(confirmxiao));
        while (!findclick(shopxiao));
        while (!findclick(completeall));
        while (findclick(completeall));
        while (!findclick(confirmxiao));
        while (findclick(confirmxiao));
        XIAOWU = false;
        goHome();
    }
    catch (int e) {       
        return;  
    }
}
void SLRD::getBag() {
    try {
        goHome();
        int nbdiamondbag = 0;
        int nbsectbag = 0;
        bool sectbagpresent, diamondbagpresent, eventbagpresent;
        sectbagpresent = diamondbagpresent = eventbagpresent = true;
        while (!findclick(sect)) {
            swipemiddlemenu();
        }
        adb.wait(4000);
        while (findclick(sect));
        while (!findclick(luckybagicon));
        while (findclick(luckybagicon));
        adb.wait(2000);

        while (sectbagpresent || diamondbagpresent) {
            while (nbdiamondbag < 8 && findclick(diamondbag)) {
                nbdiamondbag++;
                while(!findclick(confirmbag));
                while(findclick(confirmbag));
            }
            diamondbagpresent = false;
            while (nbsectbag < 16 && findclick(sectbag)) {
                nbsectbag++;
                while (!findclick(confirmbag));
                while (findclick(confirmbag));
            }
            sectbagpresent = false;
            //while (findclick(eventbag)) {
            //    while (!findclick(confirmbag));
            //    while (findclick(confirmbag));
            //}
            //eventbagpresent = false;
            if (find(diamondbag))diamondbagpresent = true;
            if (find(sectbag))sectbagpresent = true;
        }
        while (!findclick(croixmenu));
        while (findclick(croixmenu));
        BAG = false;
        goHome();
    }
    catch (int e) {      
        return;
    }

}
void SLRD::doTournament() {
    try {
        goHome();
        while (!findclick(sect)) {
            swipemiddlemenu();
        }
        adb.wait(4000);
        while (findclick(sect));

        while (!findclick(tournament));
        while (findclick(tournament));
        //add claim rewards
        while (!findclick(attacktournament));
        while (findclick(attacktournament));
        while (!findclick(battle));
        while (findclick(battle));
        while (!findclick(startournament));
        while (findclick(startournament));
        while (!findclick(confirmendbattle));
        while (findclick(confirmendbattle));
        while (!findclick(attacktournament));
        while (!findclick(sweeptournament));
        while (findclick(sweeptournament));
        while (!findclick(sweepagain));
        while (!findclick(croixmenu));
        while (findclick(croixmenu));
        while (!findclick(rewardtournament));
        while (findclick(rewardtournament));
        while (!findclick(claimalltreant));
        TOURNAMENT = false;
        goHome();
    }
    catch (int e) {
        return;
    }
}

void SLRD::doTyrant() {
    try {
        goHome();
        while (!findclick(sect)) {
            swipemiddlemenu();
        }
        adb.wait(4000);
        while (findclick(sect));
        while (!findclick(tyrant)) {
            adb.swipe(9 * dimX / 10, dimY / 2, dimX / 10, dimY / 2, 1000);
        }
        while (findclick(tyrant));
        while (!findclick(claimtask));
        adb.wait(2000);
        while (findclick(congrats)||findclick(claimtask));
        while (!findclick(fighttyrant));
        while (findclick(fighttyrant));
        if (getDay() == Monday) {
            while (!findclick(battle));
            while (findclick(battle));
            while (!findclick(fighttingtyrant));
            while (findclick(fighttingtyrant));
            while (!findclick(confirmendbattle));
            while (findclick(confirmendbattle));
            while (!findclick(fighttyrant));
            while (findclick(fighttyrant));
            while (!findclick(sweeptyrant));
            while (!findclick(confirmpot));
            while (findclick(confirmpot));
        }
        else {
            //while (!findclick(sweeptyrant));
            //while (!findclick(confirmpot));
            //while (findclick(confirmpot));
            //while (findclick(fighttyrant));
            while (!findclick(sweeptyrant));
            while (!findclick(confirmpot));
            while (findclick(confirmpot));
        }
        while (!findclick(pointstyrant));
        while (findclick(pointstyrant));
        while (!findclick(claimalltyrant));
        while (!findclick(congrats));
        while (findclick(congrats));
        TYRANT = false;
        goHome();

    }
    catch (int e) {
        return;
    }
}

int SLRD::getDay() {
    std::time_t t = std::time(nullptr);
    std::tm now;
    localtime_s(&now, &t);
    int dayOfWeek = now.tm_wday;
    // Ajuster la valeur pour obtenir un chiffre entre 1 et 7
    if (dayOfWeek == 0) {
        dayOfWeek = 7; // Dimanche est repr�sent� par 7
    }
    std::cout << "Le jour de la semaine est : " << dayOfWeek << std::endl;
    return dayOfWeek;
}

void SLRD::swipeleftmenu() {
    for (int i = 0; i < 5; i++) {
        adb.swipe(100, 500, dimX - 100, 500,500);
    }
}
void SLRD::swipemiddlemenu() {
    swipeleftmenu();
    for (int i = 0; i < 2; i++) {
        adb.swipe(dimX - dimX/4, 500, 100, 500, 500);
    }
}
void SLRD::swiperightmenu() {
    for (int i = 0; i < 5; i++) {
        adb.swipe(dimX - 100, 500,100, 500,500);
    }
}

bool SLRD::findclick(std::string imgtoclick,std::string imgtofind){
    for (int i = 0; i < 1; i++) {
        adb.screenshot();
        if (op.checkImage(imgtofind))
        {
            if (op.findImage(imgtoclick,backg, C.x, C.y)) {
                adb.touch(C.x, C.y);
                return true;
            }
        }
    }
    return false;
}

int SLRD::getCx()const {
    return C.x;
}
int SLRD::getCy()const {
    return C.y;
}
int SLRD::getEventx()const {
    return Cevent.x;
}
int SLRD::getEventy()const {
    return Cevent.y;
}
void SLRD::setRebootCount(int nb) {
    rebootCount = nb;
}

int SLRD::getRebootCount() {
    return rebootCount;
}

void SLRD::setDimX(int x) {
    dimX = x;
}
void SLRD::setDimY(int y) {
    dimY = y;
}
bool SLRD::findclick(std::string imgtemplate) { 
    if (rebootCount >= 50) {
        std::cout << "Relance du jeu\n" << endl;
        restartMacro = true;
    }
    while (waitMacro) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    adb.screenshot();
    if (op.findImage(imgtemplate,backg, C.x, C.y)) {
        rebootCount = 0;
        restartMacro = false;
        previousobject = imgtemplate;
        adb.touch(C.x, C.y);
        adb.wait(2000);
        return true;
    }
    if (restartMacro) {
        throw 20;  
        return false;
    }
    else {
        rebootCount++;
        return false;
    }
}

bool SLRD::getArray(std::string arrayimg) {
    while (waitMacro) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    adb.screenshot();

    if (op.findMultipleImage(arrayimg,listcoords)) {
        rebootCount = 0;
        restartMacro = false;
        return true;
    }
    
    if (restartMacro) {
        throw 20;
        return false;
    }
    else {
        rebootCount++;
        return false;
    }
}

void SLRD::selectRangeCoords(std::vector <Coords>&coords, int order, pos range) {
    int i, j;
    Coords temp;
    switch (range) {
    case haut:
        for (i = 1; i < coords.size(); ++i) {
            temp = coords.at(i);

            for (j = i - 1; j >= 0 && coords.at(j).y > temp.y; --j) {
                coords.at(j + 1) = coords.at(j);
            }
            coords.at(j + 1) = temp;
        } 
    break;

    case bas:
        for (i = 1; i < coords.size(); ++i) {
            temp = coords.at(i);

            for (j = i - 1; j >= 0 && coords.at(j).y < temp.y; --j) {
                coords.at(j + 1) = coords.at(j);
            }
            coords.at(j + 1) = temp;
        }
        break;
    case gauche:
        for (i = 1; i < coords.size(); ++i) {
            temp = coords.at(i);

            for (j = i - 1; j >= 0 && coords.at(j).x > temp.x; --j) {
                coords.at(j + 1) = coords.at(j);
            }
            coords.at(j + 1) = temp;
        }
        break;
    case droite: 
        for (i = 1; i < coords.size(); ++i) {
            temp = coords.at(i);

            for (j = i - 1; j >= 0 && coords.at(j).x < temp.x; --j) {
                coords.at(j + 1) = coords.at(j);
            }
            coords.at(j + 1) = temp;
        }
        break;
    }
    if (order>=coords.size()) C = coords.at(coords.size()-1);
    else C = coords.at(order);
}

std::vector<Coords>& SLRD::getListCoords() {
    return listcoords;
}
bool SLRD::findclickEvents(std::string imgtemplate) {
    adb.screenshotEvents();
    if (op.findImage(imgtemplate,imgevents, Cevent.x, Cevent.y)) {
        adb.touch(Cevent.x, Cevent.y);
        return true;
    }
    else return false;
}
bool SLRD::findclickBusy(std::string imgtemplate) {
    adb.screenshotBusy();
    if (op.findImage(imgtemplate, imgbusy, Cbusy.x, Cbusy.y)) {
        adb.touch(Cbusy.x, Cbusy.y);
        return true;
    }
    else return false;
}

bool SLRD::clicktext(std::string targetword) {
    while (waitMacro) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    adb.screenshot();
    if (api.detectText(targetword, C.x, C.y)) {
        rebootCount = 0;
        restartMacro = false;
        adb.touch(C.x, C.y);
        adb.wait(2000);
        return true;
    }
    if (restartMacro) {
        throw 20;
        return false;
    }
    else {
        rebootCount++;
        return false;
    }
}
bool SLRD::find(std::string imgtemplate) {
    if (rebootCount >= 50) {
        std::cout << "Relance du jeu\n" << endl;
        restartMacro = true;
    }
    while (waitMacro) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    adb.screenshot();
    if (op.findImage(imgtemplate,backg, C.x, C.y)) {
        rebootCount = 0;
        restartMacro = false;
        previousobject = imgtemplate;
        return true;
    }
    if (restartMacro) {
        throw 20;
        return false;
    }
    else {
        rebootCount++;
        return false;
    }
}
bool SLRD::findEvents(std::string imgtemplate) {
    adb.screenshotEvents();
    if (op.findImage(imgtemplate,imgevents, Cevent.x, Cevent.y)) {
        return true;
    }
    else return false;
}


void SLRD::CurrentFocus() {
    for (int i = 0; i < Focus.size(); i++) {
        std::cout << Focus.size();    
        if (find(Focus.at(i))) {
            currentfocus = Focus.at(i);
           // std::cout << currentfocus;
        }
    }

}








