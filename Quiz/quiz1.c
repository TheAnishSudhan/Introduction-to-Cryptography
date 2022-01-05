#include <stdio.h>

int main() {

  char n;

  FILE *fpr;

  fpr = fopen("cipher_text.txt","r");

  FILE *nfpr;

  nfpr = fopen("plain_text.txt","wb");

  while ((n=fgetc(fpr))!=EOF)
  {

    if(n=='z')
    {
      fputc("t",nfpr);
      //fscanf(nfpr, "t");
      printf("%c\n",n );
      continue;
    }
    if(n=='Z')
    {
      fputc("T",nfpr);
      continue;
    }




  }

  fclose(fpr);
  fclose(nfpr);

  //read file with cipher text

  //input array with key

  //open new file and enter the plaintext post conversion

  return 0;
}

//Need to remove the Projects submodule from IntroToCrypto repo
/*

E

T, A , O , I , N , S , H , R

D , L

C , U , M , W , F , G , Y , P , B

V , K , J , X , Q , Z

IT IS A WELL-KNOWN ESTABLISHED FACT THROUGHOUT THE MANY-DIMENSIONAL WORLDS OF THE MULTIVERSE THAT
MOST REALLY GREAT DISCOVERIES ARE OWED TO ONE BRIEF MOMENT OF INSPIRATION. THERE'S A LOT OF SPADEWORK
FIRST, OF COURSE, BUT WATER CLINCHES THE WHOLE THING IS THE SIGHT OF, SAY, A FALLING APPLE OR A BOILING
KETTLE OR THE WATER SLIPPING OVER THE EDGE OF THE BATH. SOMETHING GOES CLICK INSIDE THE OBSERVER'S
HEAD AND THEN EVERYTHING FALLS INTO PLACE. THE SHAPE OF DNA, IT IS POPULARLY SAID, OWES ITS DISCOVERY
TO THE

Va vh j sltt-xrosr lhajutvhglb ijma agyocngoca agl fjrd-bvflrhvorjt soytbh oi agl fctavklyhl agja
foha yljttd nylja bvhmoklyvlh jyl oslb ao orl uyvli foflra oi vrhwvyjavor.  Aglyl’h j toa oi hwjblsoyx
ivyha, oi mocyhl, uca sgja mtvrmglh agl sgotl agvrn vh agl hvnga oi, hjd, j ijttvrn jwwtl oy j uovtvrn
xlaatl oy agl sjaly htvwwvrn okly agl lbnl oi agl ujag.  Hoflagvrn nolh mtvmx vrhvbl agl ouhlykly’h
gljb jrb aglr lklydagvrn ijtth vrao wtjml.  Agl hgjwl oi BRJ, va vh wowctjytd hjvb, oslh vah bvhmoklyd
ao agl mgjrml hvnga oi j hwvyjt hajvymjhl sglr agl hmvlravha’h fvrb sjh echa ja agl yvnga ylmlwavkl
alfwlyjacyl.  Gjb gl chlb agl ltlkjaoy, agl sgotl hmvlrml oi nlrlavmh fvnga gjkl ullr j noob bljt
bviilylra.
Agvh vh agocnga oi jh hoflgos sorblyict.  Va vhr’a.  va vh ayjnvm.  Tvaatl wjyavmtlh oi vrhwvyjavor
htlla agyocng agl crvklyhl jtt agl avfl ayjklttvrn agyocng agl blrhlha fjaaly vr agl hjfl sjd agja
j rlcayvro wjhhlh agyocng j mjrbditohh gjdhajmx, jrb foha oi aglf fvhh.
Lklr soyhl, foha oi agl orlh agja gva agl lpjma EXACT mlyluyjt ajynla, gva agl syorn orl.
Ioy lpjfwtl EXAMPLE, agl slvyb byljf juoca j tljb bocngrca or j fvtl-gvng njrayd, sgvmg vr agl yvnga fvrb
soctb gjkl ullr agl mjajtdha ioy agl vrklravor oi ylwylhhlb- nyjkvajavorjt ltlmayvmvad nlrlyjavor
(j mgljw jrb vrlpgjchavutl jrb aoajttd ror-wottcavrn ioyf oi wosly sgvmg agl soytb vr zclhavor zUESTION gjb
ullr hllxvrn ioy mlracyvlh, jrb ioy agl tjmx oi sgvmg va sjh wtcrnlb vrao j alyyvutl jrb wovratlhh
sjy) sjh vr ijma gjb ud j hfjtt jrb ulsvtblylb bcmx.
Ud jroagly hayoxl oi ujb tcmx, agl hvnga oi j glyb oi svtb goyhlh njttowvrn agyocng j ivltb oi svtb
gdjmvragh soctb gjkl tlb j haycnntvrn mofwohly ao syval agl ijfoch Itdvrn Nob Hcval, uyvrnvrn hcmmoy
jrb ujtf ao agl hocth oi fvttvorh, gjb gl roa ullr ja gofl vr ulb svag hgvrntlh.  Agl vrhwvyjavor
aglylud iltt ao j rljyud iyon, sgo sjh roa vr fcmg oi j wohvavor ao fjxl j hajyatvrn morayvucavor
ao agl ivltb oi aorl wolayd.
Fjrd mvkvtvqjavorh CIVILIZATIONS gjkl ylmonrvqlb RECOGIZED agvh hgomxvrn sjhal jrb ayvlb kjyvoch flagobh ao wylklra va, foha
oi aglf vrkotkvrn lreodjutl ENeOYABLE uca vttlnjt jaalfwah ao acrl agl fvrb vrao agl yvnga sjkltlrnag ud agl
chl oi lpoavm glyujnl oy dljha wyobcmah.  Va rlkly soyxh wyowlytd.

*/
