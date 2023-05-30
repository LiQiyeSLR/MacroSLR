#include "SLRD.h"

SLRD::SLRD(int SizeX,int SizeY) {
    C.x = C.y =eventy=eventx= 0;
    MAIL = FRIENDS = HELL= ICEFIRE= BAG= HERB= RACE= THEATER= MYSTERY= XIAOWU= TRIAL = TASKS= TREANT= ABYSS= ENERGY = PAGODA = TYRANT= ELEMENT= TOURNAMENT = false;
    MAIL = FRIENDS = HELL = ICEFIRE = BAG = HERB = THEATER = MYSTERY = XIAOWU=TREANT=ELEMENT =true;
    dimX = SizeX;
    dimY = SizeY;
    endmacro = false;
    restartMacro=true;
    waitMacro=false;
    previousobject = croixmenu;
    setOrder();
}
void SLRD::setOrder() {
    for (int i = 0; i < 20; i++) {
        Order[i] = i;
    }
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
          //  restartMacro = false;
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

                break;
            }
            if (ELEMENT) {
                doElement();
                break;
            }
            if (TREANT) {
                doTreant();
                break;
            }
            if (TRIAL) {
                doTrial();
                break;
            }
        } 
        if (macroEnd()) {
            std::cout << "trouvé!" << std::endl;
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
        for (int i = 0; i < 5; i++) {
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
            adb.wait(1000);
            //while (!findclick(crossad)) {
            //    if (!findclick(crossad2))break;
            //}
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
        adb.wait(2000);
        while (findclick(claimall)) {
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



void SLRD::doHell() {// à revoir quick challenge
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
            while (!find(canwatch));
            while (!findclick(watchtheater));
            while (!find(adwatched));//see for other adwatched in diff languages
            //while (!findclick(crossad)) {
            //    if (!findclick(crossad2))break;
            //}
            adb.back();
            adb.wait(2000);
        }
       /* adb.wait(1000);
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
        findclick(congrats);*/
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
        swipemiddlemenu();
        while (!findclick(sect));
        while (!findclick(luckybagicon));
        adb.wait(2000);
        while (findclick(diamondbag)&&nbdiamondbag<8) {
            nbdiamondbag++;
            adb.wait(2000);
            findclick(confirmbag);
            adb.wait(2000);
            while (findclick(sectbag)) {
                adb.wait(2000);
                findclick(confirmbag);
                adb.wait(2000);
            }
        }
        while (!findclick(croixmenu));
        BAG = false;
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
        dayOfWeek = 7; // Dimanche est représenté par 7
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
    return eventx;
}
int SLRD::getEventy()const {
    return eventy;
}
void SLRD::setRebootCount(int nb) {
    rebootCount = nb;
}

int SLRD::getRebootCount() {
    return rebootCount;
}


bool SLRD::findclick(std::string imgtemplate) { 
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
    if (op.findImage(imgtemplate,imgevents, eventx, eventy)) {
        adb.touch(eventx, eventy);
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
    if (op.findImage(imgtemplate,imgevents, eventx, eventy)) {
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

void SLRD::filterLogcat()
{
    std::system("adb logcat | findstr instance:QUI");
}


bool SLRD::stringLogcat(const std::string& searchString)
{
    std::string logcatEntry;
    std::time_t currentTime = std::time(nullptr);
    std::tm now;
    std::tm* twoSecondsAgo = nullptr;

    std::time(&currentTime);
    localtime_s(&now, &currentTime);
    localtime_s(twoSecondsAgo,&currentTime);
    twoSecondsAgo->tm_sec -= 2;

    while (std::getline(std::cin, logcatEntry))
    {
        std::string timestampStr = logcatEntry.substr(0, logcatEntry.find(' '));
        std::tm timestamp = {};

        if (sscanf_s(timestampStr.c_str(), "%d-%d-%d", &timestamp.tm_mon, &timestamp.tm_mday, &timestamp.tm_year) == 3)
        {
            timestamp.tm_year -= 1900;
            timestamp.tm_mon -= 1;

            std::string timePart = timestampStr.substr(timestampStr.find(' ') + 1);
            if (sscanf_s(timePart.c_str(), "%d:%d:%d", &timestamp.tm_hour, &timestamp.tm_min, &timestamp.tm_sec) == 3)
            {
                std::time_t timestampTime = std::mktime(&timestamp);

                if (timestampTime >= std::mktime(twoSecondsAgo) && timestampTime <= currentTime)
                {
                    if (logcatEntry.find(searchString) != std::string::npos)
                    {
                        std::cout << "Match found!" << std::endl;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}




