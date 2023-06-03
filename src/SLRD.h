#ifndef SLRD_H
#define SLRD_H
#include "../MSVC/14.35.32215/include/iostream"
#include "../MSVC/14.35.32215/include/array"
#include "../MSVC/14.35.32215/include/memory"
#include "../MSVC/14.35.32215/include/ctime"
#include "../MSVC/14.35.32215/include/filesystem"
#include "../MSVC/14.35.32215/include/atomic"
#include "../MSVC/14.35.32215/include/chrono"
#include "../MSVC/14.35.32215/include/thread"
#include "../MSVC/14.35.32215/include/stdexcept"
#include "../MSVC/14.35.32215/include/cstdio"
#include "fopencv.h"
#include "fadb.h"
#include "ocr.h"
#include "sysCommands.h"

enum pos {haut,bas,gauche,droite};
#define Monday 1
#define Tuesday 2
#define Wednesday 3
#define Thursday 4
#define Friday 5
#define Saturday 6
#define Sunday 7
class SLRD
{
public:
	SLRD(int dimX,int dimY);
	void startSLRD();
	//Activités
	void doHell();
	void goHome();
	void doTheater();
	void doIcefire();
	void doMail();
	void getBag();
	void doFriends();
	void doTasks();
	void doShop();
	void doXiao();
	void doHerb();
	void doRace();
	void doMystery();
	void doDispatch();
	void doTrial();
	void doTreant();
	void doElement();
	void doTournament();
	void doTyrant();
	//Outils
	bool findclick(std::string imgtemplate, std::string background);
	bool findclick(std::string imgtemplate);
	bool findclickEvents(std::string imgtemplate);
	bool findclickBusy(std::string imgtemplate);
	bool getArray(std::string imgtemplate);
	bool find(std::string imgtemplate);
	bool findEvents(std::string imgtemplate);
	bool clicktext(std::string imgtemplate);
	void selectRangeCoords(std::vector <Coords>&coords,int order,pos range);
	void swipeleftmenu();
	void swipemiddlemenu();
	void swiperightmenu();
	void CurrentFocus();
	void macroLoop();
	bool macroEnd();
	int getDay();
	bool stringLogcat(const std::string& searchString);
	void recursiveSearch(const std::filesystem::path& dirPath, std::vector<std::string>& Focus);
	int getCx()const;
	int getCy()const;
	int getEventx()const;
	void setOrder();
	int getEventy()const;
	int getRebootCount();
	void setRebootCount(int nb);
	int rebootCount;
	int Order[20];
	std::vector<Coords>& getListCoords();
	std::atomic<bool> restartMacro;
	std::atomic<bool> waitMacro;
	std::string previousobject;
	std::vector<std::string>nextimg;
	std::vector<std::string>multimg;
	bool endmacro;
	bool TRIAL,FRIENDS,MAIL,HELL,ICEFIRE,DISPATCH,TOURNAMENT,BAG,HERB,RACE,THEATER,MYSTERY,PAGODA,XIAOWU,ENERGY,TASKS,ABYSS,TYRANT,ELEMENT,TREANT;


	//General
	std::string General = "./imgObjects/";
	std::string back = General + "back.png";
	std::string battle = General + "battle.png";
	std::string cancel = General + "cancel.png";
	std::string confirm = General + "confirm.png";
	std::string xw = General + "xw.png";
	std::string sweep = General + "sweep.png";
	std::string claimall = General + "claimall.png";
	std::string Case = General + "Case.png";
	std::string BP = General + "BP.png";
	std::string buy = General + "buy.png";
	std::string Casecheck = General + "Casecheck.png";
	std::string changelineup = General + "changelineup.png";
	std::string confirmpurchase = General + "confirmpurchase.png";
	std::string congrats = General + "congrats.png";
	std::string free = General + "free.png";
	std::string home = General + "home.png";
	std::string exchange = General + "exchange.png";
	std::string max = General + "max.png";
	std::string plus10 = General + "plus10.png";
	std::string replace = General + "replace.png";
	std::string points = General + "points.png";
	std::string arrow = General + "arrow.png";
	std::string share = General + "share.png";
	std::string completeall = General + "completeall.png";
	std::string crossad = General + "crossad.png";
	std::string crossad2 = General + "crossad2.png";
	std::string timevoucher = General + "timevoucher.png";
	std::string start = General + "start.png";
	std::string autoskills = General + "autoskills.png";
	std::string speed2 = General + "speed2.png";
	std::string help = General + "help.png";
	std::string skip = General + "skip.png";
	std::string adwatched = General + "adwatched.png";
	std::string waitconnexion = General + "waitconnexion.png";
	std::string reconnect = General + "reconnect.png";

	
	//Grandmaster
	std::string Grandmaster = General + "Grandmaster/";
	std::string autogm = Grandmaster + "autogm.png";
	std::string grandmaster = Grandmaster + "grandmaster.png";
		//Pot
	std::string Pot = General + "Pot/";
	std::string confirmpot = Pot+ "confirmpot.png";
	std::string deliver = Pot + "deliver.png";
	std::string godlyrefresh = Pot + "godlyrefresh.png";
	std::string herbreward = Pot + "herbreward.png";
	std::string potchoose = Pot + "potchoose.png";
	std::string potnotice = Pot + "potnotice.png";
	std::string shipnow = Pot + "shipnow.png";
	std::string twopot = Pot + "twopot.png";
	std::string protect = Pot + "protect.png";
	std::string confirmdeliver = Pot + "confirmdeliver.png";
	std::string claimallpot = Pot + "claimallpot.png";
		//Race 
	std::string Race = General + "Race/";
	std::string claimrace = Race + "claimrace.png";
	std::string racechoose = Race + "racechoose.png";

	//Energy 
	std::string Energy = General + "Energy/";
	std::string breakthrough = Energy+"breakthrough.png";
	std::string grandmasterchoose = Energy + "grandmasterchoose.png";
	std::string limitbuyenergy = Energy + "limitbuyenergy.png";
	std::string oneclick = Energy + "oneclick.png";
	std::string redplus3 = Energy + "redplus3.png";
	std::string redplus4 = Energy + "redplus4.png";
	std::string repereEnergy = Energy + "repereEnergy.png";


	//Sect
	//Bag
	std::string Bag = General + "Sect/Bag/";
	std::string diamondbag = Bag + "diamondbag.png";
	std::string luckybagicon = Bag + "luckybagicon.png";
	std::string confirmbag = Bag + "confirmbag.png";
	std::string sectbag = Bag + "sectbag.png";
	
	//Dispatch
	std::string Dispatch = General + "Sect/Dispatch/";
	std::string claimdispatch = Dispatch + "claimdispatch.png";
	std::string deploy = Dispatch + "deploy.png";
	std::string dispatch = Dispatch + "dispatch.png";
	std::string dispatchbuilding = Dispatch + "dispatchbuilding.png";

	//Tournament
	std::string Tournament = General + "Sect/Tournament/";
	std::string attacktournament = Tournament + "attacktournament.png";
	std::string sweepagain = Tournament + "sweepagain.png";
	std::string sweeptournament = Tournament + "sweeptournament.png";
	std::string tournament = Tournament + "tournament.png";
	std::string rewardtournament = Tournament + "rewardtournament.png";
	std::string startournament= Tournament + "startournament.png";
	
	//Tyrant
	std::string Tyrant = General + "Sect/Tyrant/";
	std::string claimalltyrant = Tyrant + "claimalltyrant.png";
	std::string fighttingtyrant = Tyrant + "fightingtyrant.png";
	std::string fighttyrant = Tyrant + "fighttyrant.png";
	std::string pointstyrant = Tyrant + "pointstyrant.png";
	std::string sweeptyrant = Tyrant + "sweeptyrant.png";
	std::string tyrant = Tyrant + "tyrant.png";
	//Icefire 
	std::string Icefire = General + "Icefire/";
	std::string apricot = Icefire+"apricot.png";
	std::string aromatic = Icefire + "aromatic.png";
	std::string endicefire = Icefire + "endicefire.png";
	std::string ginseng = Icefire + "ginseng.png";
	std::string octagonal = Icefire + "octagonal.png";
	std::string oneclickroll = Icefire + "oneclickroll.png";
	std::string orchid = Icefire + "orchid.png";
	std::string silk = Icefire + "silk.png";
	std::string sunflower = Icefire + "sunflower.png";
	std::string velvet = Icefire + "velvet.png";
	std::string manageherbs = Icefire + "manageherbs.png";
	std::string collection = Icefire + "collection.png";

	//Treant
	std::string Treant = General + "Treant/";
	std::string attacktreant = Treant + "attacktreant.png";
	std::string iconelement = Treant + "iconelement.png";
	std::string icontreant = Treant + "icontreant.png";
	std::string iconelementlight = Treant + "iconelementlight.png";
	std::string icontreantlight = Treant + "icontreantlight.png";
	std::string sweeptreant = Treant + "sweeptreant.png";
	std::string claimalltreant = Treant + "claimalltreant.png";
	std::string confirmendbattle = Treant + "confirmendbattle.png";
	std::string elementalpoint = Treant + "elementalpoint.png";
	std::string treantpoint = Treant + "treantpoint.png";
	std::string fightingtreant = Treant + "fightingtreant.png";
	std::string fightingelement = Treant + "fightingelement.png";
	std::string fighttreant = Treant + "fighttreant.png";
	std::string fightelement = Treant + "fightelement.png";
	std::string pointstreant = Treant + "pointstreant.png";

	//Launch
	std::string PSLR = "com.soullandrl.gp";
	std::string SLR = "com.soullandrl.gp/cc.qidea.jsfb.SplashActivity";
	std::string Launch=General+"Launch/";
	std::string croixmenu = Launch+"croixmenu.png";
	std::string login = Launch + "login.png";
	std::string server = Launch + "server.png";
	std::string iconSLR = Launch + "iconSLR.png";
	
	//Mystery
	std::string Mystery = General + "Mystery/";
	std::string mysteryid = Mystery + "mysteryid.png";
	std::string watchadmystery = Mystery + "watchadmystery.png";

	//Freebies
	std::string Freebies = General + "Freebies/";
	std::string claimfreebies =Freebies+ "claimfreebies.png";
	std::string dailyfreebies = Freebies + "dailyfreebies.png";
	std::string freebiesclaimed = Freebies + "freebiesclaimed.png";
	std::string monthlycard = Freebies + "monthlycard.png";
	std::string normalmode = Freebies + "normalmode.png";
	std::string renew = Freebies + "renew.png";
	std::string claimcard = Freebies + "claimcard.png";
	std::string sausagenotbought = Freebies + "sausagenotbought.png";
	std::string staminapurchase = Freebies + "staminapurchase.png";
	std::string sausagedone = Freebies + "sausagedone.png";
	std::string normalmodedone = Freebies + "normalmodedone.png";
	
	//Theater
	std::string Theater = General + "Theater/";
	std::string theaterchoose = Theater+ "theaterchoose.png";
	std::string theaterid = Theater + "theaterid.png";
	std::string watchtheater = Theater + "watchtheater.png";
	std::string canwatch = Theater + "canwatch.png";
	
	//Missions 
	std::string Missions = General + "Missions/";
	std::string collectmissed = Missions + "collectmissed.png";
	std::string daily = Missions + "daily.png";
	std::string weekly = Missions + "weekly.png";
	std::string claimtask = Missions + "claimtask.png";

	//menu
	std::string Menu = General+"Menu/";
	std::string academy = Menu + "academy.png";
	std::string arena = Menu + "arena.png";
	std::string beast = Menu + "beast.png";
	std::string elite = Menu + "elite.png";
	std::string friends = Menu + "friends.png";
	std::string gm = Menu + "gm.png";
	std::string hall = Menu + "hall.png";
	std::string hell = Menu + "hell.png";
	std::string icefire = Menu + "icefire.png";
	std::string iconad = Menu + "iconad.png";
	std::string iconadless = Menu + "iconadless.png";
	std::string invasion = Menu + "invasion.png";
	std::string mail = Menu + "mail.png";
	std::string metal = Menu + "metal.png";
	std::string pot = Menu + "pot.png";
	std::string ranking = Menu + "ranking.png";
	std::string rollmenu = Menu + "rollmenu.png";
	std::string sea = Menu + "sea.png";
	std::string sect = Menu + "sect.png";
	std::string shop = Menu + "shop.png";
	std::string slaughter = Menu + "slaughter.png";
	std::string sotto = Menu + "sotto.png";
	std::string soul = Menu + "soul.png";
	std::string soulforce = Menu + "soulforce.png";
	std::string story = Menu + "story.png";
	std::string treant = Menu + "treant.png";
	std::string trial = Menu + "trial.png";
	std::string mysterychest = Menu + "mysterychest.png";
	std::string pass = Menu + "pass.png";
	std::string secretshop = Menu + "secretshop.png";
	std::string dailyevents = Menu + "dailyevents.png";
	std::string monthly = Menu + "monthly.png";
	std::string store = Menu + "store.png";
	std::string tasks = Menu + "tasks.png";
	std::string xiaoassistant = Menu + "xiaoassistant.png";
	std::string rollmenuopen = Menu + "rollmenuopen.png";
	std::string bag = Menu + "bag.png";
	std::string divinetool = Menu + "divinetool.png";
	std::string hiddenweapon = Menu + "hiddenweapon.png";
	std::string soulmaster = Menu + "soulmaster.png";
	std::string spiritsoul = Menu + "spiritsoul.png";
	std::string whales = Menu + "whales.png";

	//Trial
	std::string Trial = General + "Beast/Trial/";
	std::string canexplore = Trial + "canexplore.png";
	std::string cantexplore = Trial + "cantexplore.png";
	std::string emptychest = Trial + "emptychest.png";
	std::string exploredcase = Trial + "exploredcase.png";
	std::string levelcomplete = Trial + "levelcomplete.png";
	std::string gianttrial = Trial + "gianttrial.png";
	std::string levelnotcomplete = Trial + "levelnotcomplete.png";
	std::string beast10k = Trial + "beast10k.png";
	std::string beast5k = Trial + "beast5k.png";
	//XiaoWu
	std::string XiaoWu = General + "XiaoWu/";
	std::string confirmxiao =XiaoWu+ "confirmxiao.png";
	std::string dailies= XiaoWu + "dailies.png";
	std::string gameplay = XiaoWu + "gameplay.png";
	std::string gameplaynotice = XiaoWu + "gameplaynotice.png";
	std::string ondailies = XiaoWu + "ondailies.png";
	std::string ongameplay = XiaoWu + "ongameplay.png";
	std::string onrankingxiao = XiaoWu + "onrankingxiao.png";
	std::string onsectxiao = XiaoWu + "onsectxiao.png";
	std::string onshopxiao = XiaoWu + "onshopxiao.png";
	std::string rankingxiao = XiaoWu + "rankingxiao.png";
	std::string sectxiao = XiaoWu + "sectxiao.png";
	std::string shopxiao = XiaoWu + "shopxiao.png";

	//Pagoda
	std::string Pagoda = General + "Pagoda/";
	std::string battlepagoda = Pagoda + "battlepagoda.png";
	std::string createpagoda = Pagoda + "createpagoda.png";
	std::string fullpagoda = Pagoda + "fullpagoda.png";
	std::string pagodachoice = Pagoda + "pagodachoice.png";
	std::string pagodalevels = Pagoda + "pagodalevels.png";
	std::string pagodapin = Pagoda + "pagodapin.png";
	std::string refreshpagoda20 = Pagoda + "refreshpagoda20.png";
	std::string victorypagoda = Pagoda + "victorypagoda.png";
	std::string clashpagoda = Pagoda + "clashpagoda.png";
	std::string busy = Pagoda + "busy.png";
	std::string gonow = Pagoda + "gonow.png";

	//Hell
	std::string Hell = General+"Hell/";
	std::string bphell =Hell+ "bphell.png";
	std::string confirmhell = Hell + "confirmhell.png";
	std::string endclickhell = Hell + "endclickhell.png";
	std::string endofchallengehell= Hell + "endofchallengehell.png";
	std::string oneclickhell = Hell + "oneclickhell.png";
	std::string shophell = Hell + "shophell.png";
	std::string shopiconhell = Hell + "shopiconhell.png";
	std::string teamfillhell = Hell + "teamfillhell.png";
	std::string oneclicknotavailable = Hell + "oneclicknotavailablehell.png";
	std::string advance = Hell + "advance.png";
	
	//Silverweiss
	std::string Silverweiss = General + "Silverweiss/";
	std::string changesilverweiss = Silverweiss+"changesilverweiss.png";
	std::string chooseenemy = Silverweiss + "chooseenemy.png";
	std::string formparty = Silverweiss + "formparty.png";
	std::string registerapplications = Silverweiss + "registerapplications.png";
	std::string registerpartysilverweiss = Silverweiss + "registerpartysilverweiss.png";
	std::string silverweisschoose = Silverweiss + "silverweisschoose.png";
	std::string startbattlesilverweiss = Silverweiss + "startbattlesilverweiss.png";
	std::string victorysilverweiss = "victorysilverweiss.png";

	//Mail
	std::string Mail = General + "Mail/";
	std::string newmail = Mail + "newmail.png";

	//Friend 
	std::string Friends = General + "Friend/";
	std::string sendall = Friends + "sendall.png";
	std::string claimallfriends = Friends + "claimallfriends.png";

	//Abyss
	std::string Abyss = General + "Abyss/";
	std::string abysschoose = Abyss+"abysschoose.png";
	std::string abyssiconshop = Abyss + "abyssiconshop.png";
	std::string changeabyss = Abyss + "changeabyss.png";
	std::string continueabyss = Abyss + "continueabyss.png";
	std::string DefeatAbyss = Abyss + "DefeatAbyss.png";
	std::string finalchestabyss = Abyss + "finalchestabyss.png";
	std::string rewardchestabyss = Abyss + "rewardchestabyss.png";
	std::string starsabyss = Abyss + "starsabyss.png";
	std::string starabyss = Abyss + "startabyss.png";
	std::string team1 = Abyss + "team1.png";
	std::string team2 = Abyss + "team2.png";
	std::string team3 = Abyss + "team3.png";
	std::string tokenshop = Abyss + "tokenshop.png";
	std::string victoryabyss = Abyss + "victoryabyss.png";
	std::string zero= Abyss + "zero.png";
	std::string one= Abyss + "one.png";
	std::string two= Abyss + "two.png";
	std::string three= Abyss + "three.png";
	std::string four= Abyss + "four.png";
	std::string five= Abyss + "five.png";
	std::string six= Abyss + "six.png";
	std::string seven= Abyss + "seven.png";
	std::string eight= Abyss + "eight.png";
	std::string nine= Abyss + "nine.png";
	std::string BN= Abyss + "BN.png";
	
	//Shop
	std::string Shop = General + "Shop/";
	std::string gold = Shop + "gold.png";
	std::string shopdiamond = Shop + "shopdiamond.png";
	std::string shoprefresh = Shop + "shoprefresh.png";
	std::string sold = Shop + "sold.png";

	//Whales
	std::string Whales = General + "Whales/";
	std::string autowhale =Whales+ "autowhale.png";
	std::string killrewardwhale = Whales + "killrewardwhale.png";
	std::string secthonorwhale = Whales + "secthonorwhale.png";
	std::string solohonorwhale = Whales + "solohonorwhale.png";
	std::string whaleid = Whales + "whaleid.png";

	
	std::vector<std::string>Focus;
	std::string backg = "./img/screenshot.png";
	std::string imgevents = "./img/screenshotEvents.png";
	std::string imgbusy = "./img/screenshotBusy.png";
		;
private:
	std::string currentfocus;
	std::vector<Coords>listcoords;
	int dimX,dimY;
	Coords C,Cevent,Cbusy;
	fopencv op;
	fadb adb;
	ocr api;
	sysCommands sys;
};
#endif
