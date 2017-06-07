
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#define MIDICHANNEL 0 // DEPRECATED!
void xpatch_init2(int fwid);
extern "C" __attribute__ ((section(".boot"))) void xpatch_init(int fwid){
  xpatch_init2(fwid);
}

void PatchMidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2);

     int32buffer AudioInputLeft;
     int32buffer AudioInputRight;
     int32buffer AudioOutputLeft;
     int32buffer AudioOutputRight;
     typedef enum { A_STEREO, A_MONO, A_BALANCED } AudioModeType;
     AudioModeType AudioOutputMode = A_STEREO;
     AudioModeType AudioInputMode = A_STEREO;
static void PropagateToSub(ParameterExchange_t *origin) {
      ParameterExchange_t *pex = (ParameterExchange_t *)origin->finalvalue;
      PExParameterChange(pex,origin->modvalue,0xFFFFFFEE);
}
class rootc{
   public:
    static const uint32_t NPEXCH = 35;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[7];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_KickEnv__1_Threshold = 0;
static const int PARAM_INDEX_mix__1_gain1 = 1;
static const int PARAM_INDEX_mix__1_gain2 = 2;
static const int PARAM_INDEX_schmitttrigger__1_hysteresis = 3;
static const int PARAM_INDEX_NoiseGate__1_Pre = 4;
static const int PARAM_INDEX_NoiseGate__1_smooth2__1_colon_risetime = 5;
static const int PARAM_INDEX_NoiseGate__1_smooth2__1_colon_falltime = 6;
static const int PARAM_INDEX_NoiseGate__1_a_slash_d_colon_a = 7;
static const int PARAM_INDEX_NoiseGate__1_a_slash_d_colon_d = 8;
static const int PARAM_INDEX_NoiseGate__1_Threshold = 9;
static const int PARAM_INDEX_hp__1_pitch = 10;
static const int PARAM_INDEX_hp__1_reso = 11;
static const int PARAM_INDEX_mix__3_gain1 = 12;
static const int PARAM_INDEX_mix__3_gain2 = 13;
static const int PARAM_INDEX_schmitttrigger__2_hysteresis = 14;
static const int PARAM_INDEX_mix__2_gain1 = 15;
static const int PARAM_INDEX_mix__2_gain2 = 16;
static const int PARAM_INDEX_hp__2_pitch = 17;
static const int PARAM_INDEX_hp__2_reso = 18;
static const int PARAM_INDEX_mix__4_gain1 = 19;
static const int PARAM_INDEX_mix__4_gain2 = 20;
static const int PARAM_INDEX_dial__2_value = 21;
static const int PARAM_INDEX_NoiseGate__2_Pre = 22;
static const int PARAM_INDEX_NoiseGate__2_smooth2__1_colon_risetime = 23;
static const int PARAM_INDEX_NoiseGate__2_smooth2__1_colon_falltime = 24;
static const int PARAM_INDEX_NoiseGate__2_a_slash_d_colon_a = 25;
static const int PARAM_INDEX_NoiseGate__2_a_slash_d_colon_d = 26;
static const int PARAM_INDEX_NoiseGate__2_Threshold = 27;
static const int PARAM_INDEX_dial__1_value = 28;
static const int PARAM_INDEX_ad__1_a = 29;
static const int PARAM_INDEX_ad__1_d = 30;
static const int PARAM_INDEX_ad__1_s = 31;
static const int PARAM_INDEX_ad__1_r = 32;
static const int PARAM_INDEX_lp__1_pitch = 33;
static const int PARAM_INDEX_lp__1_reso = 34;
/* controller classes */
/* object classes */
class instanceoutconfig__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
ADAU1961_WriteRegister(0x4023,(33<<2)+3);
ADAU1961_WriteRegister(0x4024,(33<<2)+3);
AudioOutputMode = A_STEREO;

}
  public: void Dispose() {
}
  public: void dsp (  ){
}
}
;class instanceKickEnv__1{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instanceKickEnv__1_Threshold;
    static const uint32_t NPEXCH = 3;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_ahd__1_a = 0;
static const int PARAM_INDEX_ahd__1_d = 1;
static const int PARAM_INDEX_Threshold_value = 2;
/* controller classes */
/* object classes */
class instancei__2{
  public: // v1
  instanceKickEnv__1 *parent;
  public: void Init(instanceKickEnv__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t & outlet_out  ){
outlet_out= 64;

}
}
;class instance_dash___1{
  public: // v1
  instanceKickEnv__1 *parent;
  public: void Init(instanceKickEnv__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in1,
const int32_t  inlet_in2,
int32_t  & outlet_out  ){
outlet_out= inlet_in1-inlet_in2 ;
}
}
;class instancekeyb__1{
  public: // v1
  instanceKickEnv__1 *parent;
uint8_t _gate;
uint8_t _velo;
uint8_t _rvelo;

  public: void Init(instanceKickEnv__1 * _parent) {
parent = _parent;
_gate = 0;

}
  public: void Dispose() {
}
  public: void dsp (bool  & outlet_gate,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_gate= _gate<<27;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 9) && (data2)) {if (data1 == 64) {
   _velo = data2;
   _gate = 1;
}
} else if (((status == MIDI_NOTE_ON + 9) && (!data2))||          (status == MIDI_NOTE_OFF + 9)) {
  if (data1 == 64) {
    _rvelo = data2;
    _gate = 0;
  }
} else if ((status == 9 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instanceahd__1{
  public: // v1
  instanceKickEnv__1 *parent;
KeyValuePair KVP_instanceahd__1_a;
KeyValuePair KVP_instanceahd__1_d;
int32_t val;

  public: void Init(instanceKickEnv__1 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_ahd__1_a].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instanceahd__1_a,ObjectKvpRoot, "ahd_1:a" ,&parent->PExch[PARAM_INDEX_ahd__1_a], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instanceahd__1_a);
parent->PExch[PARAM_INDEX_ahd__1_d].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instanceahd__1_d,ObjectKvpRoot, "ahd_1:d" ,&parent->PExch[PARAM_INDEX_ahd__1_d], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instanceahd__1_d);
val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
int32_t  & outlet_env,
int param_a,
int param_d  ){
if (inlet_trig > 0) {
  int32_t t;
  MTOF(-param_a,t);
  val += t>>6;
}
else {
  int32_t t;
  MTOF(-param_d,t);
  val -= t>>6;
}
val = __USAT(val,27);
outlet_env = val;

}
}
;class instancexfade__1{
  public: // v1
  instanceKickEnv__1 *parent;
  public: void Init(instanceKickEnv__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_i1,
const int32_t  inlet_i2,
const int32_t  inlet_c,
int32_t  & outlet_o  ){
   {
      int64_t a = (int64_t)inlet_i2 * inlet_c;
      a += (int64_t)inlet_i1 * ((128<<20)-inlet_c);
      outlet_o= a>>27;
   }

}
}
;class instanceoutlet__1{
  public: // v1
  instanceKickEnv__1 *parent;
int32_t _outlet;

  public: void Init(instanceKickEnv__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_outlet  ){
  _outlet = inlet_outlet;

}
}
;class instancei__1{
  public: // v1
  instanceKickEnv__1 *parent;
  public: void Init(instanceKickEnv__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t & outlet_out  ){
outlet_out= 64;

}
}
;class instanceThreshold{
  public: // v1
  instanceKickEnv__1 *parent;
KeyValuePair KVP_instanceThreshold_value;
  public: void Init(instanceKickEnv__1 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_Threshold_value].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instanceThreshold_value,ObjectKvpRoot, "Threshold" ,&parent->PExch[PARAM_INDEX_Threshold_value], 0, 1<<27);
  KVP_RegisterObject(&KVP_instanceThreshold_value);
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out,
int param_value  ){
outlet_out= param_value;

}
}
;/* controller instances */
/* object instances */
     instancei__2 instancei__2_i;
     instance_dash___1 instance_dash___1_i;
     instancekeyb__1 instancekeyb__1_i;
     instanceahd__1 instanceahd__1_i;
     instancexfade__1 instancexfade__1_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instancei__1 instancei__1_i;
     instanceThreshold instanceThreshold_i;
/* net latches */
    int32_t  net1Latch;
    int32_t  net3Latch;
    int32_t net4Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[3]= {
      -134217728,
      14680064,
      134217728
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
// on Parent: propagate Threshold false KickEnv__1Threshold_value
parent->PExch[PARAM_INDEX_KickEnv__1_Threshold].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_KickEnv__1_Threshold].finalvalue = (int32_t)(&(parent->instanceKickEnv__1_i.PExch[instanceKickEnv__1::PARAM_INDEX_Threshold_value]));
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<3;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instancei__2_i.Init(this );
   instance_dash___1_i.Init(this );
   instancekeyb__1_i.Init(this );
   instanceahd__1_i.Init(this );
   instancexfade__1_i.Init(this );
   instanceoutlet__1_i.Init(this );
   instancei__1_i.Init(this );
   instanceThreshold_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instanceThreshold_i.Dispose();
   instancei__1_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancexfade__1_i.Dispose();
   instanceahd__1_i.Dispose();
   instancekeyb__1_i.Dispose();
   instance_dash___1_i.Dispose();
   instancei__2_i.Dispose();

}
  public: void dsp (int32_t  & outlet_outlet__1  ){
int i; /*...*/
//--------- <nets> -----------//
    bool  net0;
    int32_t  net1;
    int32_t  net2;
    int32_t  net3;
    int32_t net4;
    int32_t net5;
    int32_t  net6;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancei__2_i.dsp(net5);
  instance_dash___1_i.dsp((net5<<21), net3Latch, net6);
  instancekeyb__1_i.dsp(net0, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instanceahd__1_i.dsp(net0, net3, PExch[PARAM_INDEX_ahd__1_a].finalvalue, PExch[PARAM_INDEX_ahd__1_d].finalvalue);
  instancexfade__1_i.dsp(net6, (net4Latch<<21), net1Latch, net2);
  instanceoutlet__1_i.dsp(net2);
  instancei__1_i.dsp(net4);
  instanceThreshold_i.dsp(net1, PExch[PARAM_INDEX_Threshold_value].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net1Latch = net1;
net3Latch = net3;
net4Latch = net4;
//--------- </net latch copy> ----------//
   outlet_outlet__1 = instanceoutlet__1_i._outlet;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 1 > 0 && dev > 0 && 1 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
        if ((status == 9 + MIDI_CONTROL_CHANGE)&&(data1 == 3)) {
            PExParameterChange(&parent->PExch[PARAM_INDEX_KickEnv__1_Threshold],(data2!=127)?data2<<20:0x07FFFFFF, 0xFFFD);
        }
}
}
}
;class instance_star___2{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_a,
const int32buffer  inlet_b,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= ___SMMUL(inlet_a<<3,inlet_b[buffer_index]<<2);

}
}
}
;class instancemix__1{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancemix__1_gain1;
KeyValuePair KVP_instancemix__1_gain2;
  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_mix__1_gain1].pfunction = pfun_signed_clamp_fullrange_squarelaw;
  SetKVP_IPVP(&KVP_instancemix__1_gain1,ObjectKvpRoot, "mix_1:gain1" ,&parent->PExch[PARAM_INDEX_mix__1_gain1], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancemix__1_gain1);
parent->PExch[PARAM_INDEX_mix__1_gain2].pfunction = pfun_signed_clamp_fullrange_squarelaw;
  SetKVP_IPVP(&KVP_instancemix__1_gain2,ObjectKvpRoot, "mix_1:gain2" ,&parent->PExch[PARAM_INDEX_mix__1_gain2], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancemix__1_gain2);
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_bus__in,
const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
int32buffer  & outlet_out,
int param_gain1,
int param_gain2  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   int32_t accum = ___SMMUL(inlet_in1[buffer_index],param_gain1);
   accum = ___SMMLA(inlet_in2[buffer_index],param_gain2,accum);
;   outlet_out[buffer_index]=  __SSAT(inlet_bus__in[buffer_index] + (accum<<1),28);

}
}
}
;class instanceschmitttrigger__1{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instanceschmitttrigger__1_hysteresis;
  static const int blepvoices = 8;
  int16_t *oscp[blepvoices];
  uint32_t nextvoice;
  int32_t i0;

  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_schmitttrigger__1_hysteresis].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instanceschmitttrigger__1_hysteresis,ObjectKvpRoot, "schmitttrigger_1" ,&parent->PExch[PARAM_INDEX_schmitttrigger__1_hysteresis], 0, 1<<27);
  KVP_RegisterObject(&KVP_instanceschmitttrigger__1_hysteresis);
    int j;
    for(j=0;j<blepvoices;j++)
      oscp[j] = &blept[BLEPSIZE-1];
   nextvoice = 0;
   i0 = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
int32buffer  & outlet_out,
int param_hysteresis  ){
  int j;
  int16_t *lastblep = &blept[BLEPSIZE-1];
  for(j=0;j<BUFSIZE;j++){
    int i;
    int i1 = inlet_in[j]>>2;
    i1 += (nextvoice&1)?param_hysteresis:-param_hysteresis;
    int32_t sum=0;
    if ((i1>0)&&!(i0>0)){   // dispatch
      nextvoice = (nextvoice+1)&(blepvoices-1);
      int32_t x = 64-((-i0<<6)/(i1-i0));
      oscp[nextvoice] = &blept[x];
    } else if ((i1<0)&&!(i0<0)){   // dispatch
      nextvoice = (nextvoice+1)&(blepvoices-1);
      int32_t x = 64-((i0<<6)/(i0-i1));
      oscp[nextvoice] = &blept[x];
    }
    i0 = i1;
    for(i=0;i<blepvoices;i++){ // sample
      int16_t *t = oscp[i];
      if (i&1) sum+=*t; else sum-=*t; 
      t+=64;
      if (t>=lastblep) t=lastblep;
      oscp[i]=t;
    }
    sum -= ((((nextvoice+1)&1)<<1)-1)<<13;
    outlet_out[j]=sum<<13;
  }
}
}
;class instancevca__1{
  public: // v1
  rootc *parent;
   int32_t prev;
    int32_t step;

  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instancexfade__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_i1,
const int32buffer  inlet_i2,
const int32_t  inlet_c,
int32buffer  & outlet_o  ){
   int32_t ccompl = ((128<<20)-inlet_c);

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   {
      int64_t a = (int64_t)inlet_i2[buffer_index] * inlet_c;
      a += (int64_t)inlet_i1[buffer_index] * ccompl;
      outlet_o[buffer_index]= a>>27;
   }

}
}
}
;class instance_star___1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_a,
const int32buffer  inlet_b,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= ___SMMUL(inlet_a<<3,inlet_b[buffer_index]<<2);

}
}
}
;class instanceNoiseGate__1{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instanceNoiseGate__1_Pre;
KeyValuePair KVP_instanceNoiseGate__1_smooth2__1_colon_risetime;
KeyValuePair KVP_instanceNoiseGate__1_smooth2__1_colon_falltime;
KeyValuePair KVP_instanceNoiseGate__1_a_slash_d_colon_a;
KeyValuePair KVP_instanceNoiseGate__1_a_slash_d_colon_d;
KeyValuePair KVP_instanceNoiseGate__1_Threshold;
    static const uint32_t NPEXCH = 6;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_Pre_value = 0;
static const int PARAM_INDEX_smooth2__1_risetime = 1;
static const int PARAM_INDEX_smooth2__1_falltime = 2;
static const int PARAM_INDEX_a_slash_d_a = 3;
static const int PARAM_INDEX_a_slash_d_d = 4;
static const int PARAM_INDEX_Threshold_value = 5;
/* controller classes */
/* object classes */
class instancePre{
  public: // v1
  instanceNoiseGate__1 *parent;
KeyValuePair KVP_instancePre_value;
  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_Pre_value].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancePre_value,ObjectKvpRoot, "Pre" ,&parent->PExch[PARAM_INDEX_Pre_value], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancePre_value);
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out,
int param_value  ){
outlet_out= param_value;

}
}
;class instance_star___2{
  public: // v1
  instanceNoiseGate__1 *parent;
  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_a,
const int32buffer  inlet_b,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= ___SMMUL(inlet_a<<3,inlet_b[buffer_index]<<2);

}
}
}
;class instancemuls__1{
  public: // v1
  instanceNoiseGate__1 *parent;
  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
int32buffer  & outlet_out  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_out[buffer_index]= __SSAT(inlet_in[buffer_index],25)<<3;
}
}
}
;class instancefollower__1{
  public: // v1
  instanceNoiseGate__1 *parent;
int32_t accu;

  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
accu = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
int32_t  & outlet_amp  ){
 int sabs = 0;
int i;  for(i=0;i<BUFSIZE;i++){    int32_t v = inlet_in[i];
    sabs += v>0?v:-v;
  }
  accu -= accu>>5;
  accu += sabs>>(5+4);
  outlet_amp = accu;

}
}
;class instancesmooth2__1{
  public: // v1
  instanceNoiseGate__1 *parent;
KeyValuePair KVP_instancesmooth2__1_risetime;
KeyValuePair KVP_instancesmooth2__1_falltime;
int32_t val;

  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_smooth2__1_risetime].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancesmooth2__1_risetime,ObjectKvpRoot, "smooth2_1:risetime" ,&parent->PExch[PARAM_INDEX_smooth2__1_risetime], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancesmooth2__1_risetime);
parent->PExch[PARAM_INDEX_smooth2__1_falltime].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancesmooth2__1_falltime,ObjectKvpRoot, "smooth2_1:falltime" ,&parent->PExch[PARAM_INDEX_smooth2__1_falltime], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancesmooth2__1_falltime);
   val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_risetime,
int param_falltime  ){
   if (inlet_in>val)      val = ___SMMLA(val-inlet_in, (-1<<26)+(param_risetime>>1),val);
      else val = ___SMMLA(val-inlet_in,(-1<<26)+(param_falltime>>1),val);
   outlet_out = val;

}
}
;class instance_eq__eq___1{
  public: // v1
  instanceNoiseGate__1 *parent;
  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in1,
const int32_t  inlet_in2,
bool  & outlet_out  ){
outlet_out= inlet_in1>inlet_in2 ;
}
}
;class instanceInput{
  public: // v1
  instanceNoiseGate__1 *parent;
int32buffer _inlet;

  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32buffer  & outlet_inlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_inlet[buffer_index] = _inlet[buffer_index];
}
}
}
;class instancea_slash_d{
  public: // v1
  instanceNoiseGate__1 *parent;
KeyValuePair KVP_instancea_slash_d_a;
KeyValuePair KVP_instancea_slash_d_d;
int32_t val;

  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a_slash_d_a].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancea_slash_d_a,ObjectKvpRoot, "a/d:a" ,&parent->PExch[PARAM_INDEX_a_slash_d_a], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancea_slash_d_a);
parent->PExch[PARAM_INDEX_a_slash_d_d].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancea_slash_d_d,ObjectKvpRoot, "a/d:d" ,&parent->PExch[PARAM_INDEX_a_slash_d_d], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancea_slash_d_d);
val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_a,
const int32_t  inlet_d,
int32_t  & outlet_env,
int param_a,
int param_d  ){
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_a + inlet_a;
  MTOF(-at,t);
  val += t>>6;
}
else {
  int32_t t;
  int32_t dt = param_d + inlet_d;
  MTOF(-dt,t);
  val -= t>>6;
}
val = __USAT(val,27);
outlet_env = val;

}
}
;class instanceThreshold{
  public: // v1
  instanceNoiseGate__1 *parent;
KeyValuePair KVP_instanceThreshold_value;
  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_Threshold_value].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instanceThreshold_value,ObjectKvpRoot, "Threshold" ,&parent->PExch[PARAM_INDEX_Threshold_value], 0, 1<<27);
  KVP_RegisterObject(&KVP_instanceThreshold_value);
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out,
int param_value  ){
outlet_out= param_value;

}
}
;class instancediv__1{
  public: // v1
  instanceNoiseGate__1 *parent;
  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out  ){
outlet_out= inlet_in >>1;
}
}
;class instance_star___1{
  public: // v1
  instanceNoiseGate__1 *parent;
  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_a,
const int32buffer  inlet_b,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= ___SMMUL(inlet_a<<3,inlet_b[buffer_index]<<2);

}
}
}
;class instanceOutput{
  public: // v1
  instanceNoiseGate__1 *parent;
int32buffer _outlet;

  public: void Init(instanceNoiseGate__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;/* controller instances */
/* object instances */
     instancePre instancePre_i;
     instance_star___2 instance_star___2_i;
     instancemuls__1 instancemuls__1_i;
     instancefollower__1 instancefollower__1_i;
     instancesmooth2__1 instancesmooth2__1_i;
     instance_eq__eq___1 instance_eq__eq___1_i;
     instanceInput instanceInput_i;
     instancea_slash_d instancea_slash_d_i;
     instanceThreshold instanceThreshold_i;
     instancediv__1 instancediv__1_i;
     instance_star___1 instance_star___1_i;
     instanceOutput instanceOutput_i;
/* net latches */
    int32_t  net6Latch;
    int32buffer  net10Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[6]= {
      134217728,
      0,
      0,
      -134217728,
      117440512,
      78643200
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
// on Parent: propagate Pre false NoiseGate__1Pre_value
parent->PExch[PARAM_INDEX_NoiseGate__1_Pre].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__1_Pre].finalvalue = (int32_t)(&(parent->instanceNoiseGate__1_i.PExch[instanceNoiseGate__1::PARAM_INDEX_Pre_value]));
// on Parent: propagate smooth2_1:risetime false NoiseGate__1smooth2__1_risetime
parent->PExch[PARAM_INDEX_NoiseGate__1_smooth2__1_colon_risetime].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__1_smooth2__1_colon_risetime].finalvalue = (int32_t)(&(parent->instanceNoiseGate__1_i.PExch[instanceNoiseGate__1::PARAM_INDEX_smooth2__1_risetime]));
// on Parent: propagate smooth2_1:falltime false NoiseGate__1smooth2__1_falltime
parent->PExch[PARAM_INDEX_NoiseGate__1_smooth2__1_colon_falltime].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__1_smooth2__1_colon_falltime].finalvalue = (int32_t)(&(parent->instanceNoiseGate__1_i.PExch[instanceNoiseGate__1::PARAM_INDEX_smooth2__1_falltime]));
// on Parent: propagate a/d:a false NoiseGate__1a_slash_d_a
parent->PExch[PARAM_INDEX_NoiseGate__1_a_slash_d_colon_a].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__1_a_slash_d_colon_a].finalvalue = (int32_t)(&(parent->instanceNoiseGate__1_i.PExch[instanceNoiseGate__1::PARAM_INDEX_a_slash_d_a]));
// on Parent: propagate a/d:d false NoiseGate__1a_slash_d_d
parent->PExch[PARAM_INDEX_NoiseGate__1_a_slash_d_colon_d].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__1_a_slash_d_colon_d].finalvalue = (int32_t)(&(parent->instanceNoiseGate__1_i.PExch[instanceNoiseGate__1::PARAM_INDEX_a_slash_d_d]));
// on Parent: propagate Threshold false NoiseGate__1Threshold_value
parent->PExch[PARAM_INDEX_NoiseGate__1_Threshold].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__1_Threshold].finalvalue = (int32_t)(&(parent->instanceNoiseGate__1_i.PExch[instanceNoiseGate__1::PARAM_INDEX_Threshold_value]));
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<6;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instancePre_i.Init(this );
   instance_star___2_i.Init(this );
   instancemuls__1_i.Init(this );
   instancefollower__1_i.Init(this );
   instancesmooth2__1_i.Init(this );
   instance_eq__eq___1_i.Init(this );
   instanceInput_i.Init(this );
   instancea_slash_d_i.Init(this );
   instanceThreshold_i.Init(this );
   instancediv__1_i.Init(this );
   instance_star___1_i.Init(this );
   instanceOutput_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instanceOutput_i.Dispose();
   instance_star___1_i.Dispose();
   instancediv__1_i.Dispose();
   instanceThreshold_i.Dispose();
   instancea_slash_d_i.Dispose();
   instanceInput_i.Dispose();
   instance_eq__eq___1_i.Dispose();
   instancesmooth2__1_i.Dispose();
   instancefollower__1_i.Dispose();
   instancemuls__1_i.Dispose();
   instance_star___2_i.Dispose();
   instancePre_i.Dispose();

}
  public: void dsp (const int32buffer  inlet_Input,
int32buffer  & outlet_Output  ){
int i; /*...*/
   for(i=0;i<BUFSIZE;i++) instanceInput_i._inlet[i] = inlet_Input[i];
//--------- <nets> -----------//
    int32buffer  net0;
    int32_t  net1;
    int32_t  net2;
    int32_t  net3;
    bool  net4;
    int32_t  net5;
    int32_t  net6;
    int32buffer  net7;
    int32_t  net8;
    int32buffer  net9;
    int32buffer  net10;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancePre_i.dsp(net8, PExch[PARAM_INDEX_Pre_value].finalvalue);
  instance_star___2_i.dsp(net8, net10Latch, net7);
  instancemuls__1_i.dsp(net7, net9);
  instancefollower__1_i.dsp(net9, net1);
  instancesmooth2__1_i.dsp(net1, net3, PExch[PARAM_INDEX_smooth2__1_risetime].finalvalue, PExch[PARAM_INDEX_smooth2__1_falltime].finalvalue);
  instance_eq__eq___1_i.dsp(net3, net6Latch, net4);
  instanceInput_i.dsp(net10);
  instancea_slash_d_i.dsp(net4, 0 , 0 , net5, PExch[PARAM_INDEX_a_slash_d_a].finalvalue, PExch[PARAM_INDEX_a_slash_d_d].finalvalue);
  instanceThreshold_i.dsp(net2, PExch[PARAM_INDEX_Threshold_value].finalvalue);
  instancediv__1_i.dsp(net2, net6);
  instance_star___1_i.dsp(net5, net9, net0);
  instanceOutput_i.dsp(net0);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net6Latch = net6;
   for(i=0;i<BUFSIZE;i++)
      net10Latch[i]=net10[i];
//--------- </net latch copy> ----------//
      for(i=0;i<BUFSIZE;i++) outlet_Output[i] = instanceOutput_i._outlet[i];

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
}
}
}
;class instancehp__1{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancehp__1_pitch;
KeyValuePair KVP_instancehp__1_reso;
biquad_state bs;biquad_coefficients bc;

  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_hp__1_pitch].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancehp__1_pitch,ObjectKvpRoot, "hp_1:pitch" ,&parent->PExch[PARAM_INDEX_hp__1_pitch], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancehp__1_pitch);
parent->PExch[PARAM_INDEX_hp__1_reso].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancehp__1_reso,ObjectKvpRoot, "hp_1:reso" ,&parent->PExch[PARAM_INDEX_hp__1_reso], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancehp__1_reso);
biquad_clearstate(&bs);

}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
const int32_t  inlet_pitch,
const int32_t  inlet_reso,
int32buffer  & outlet_out,
int param_pitch,
int param_reso  ){
      int32_t freq;
      MTOF(param_pitch + inlet_pitch,freq);
      biquad_hp_coefs(&bc,freq,INT_MAX - (__USAT(inlet_reso + param_reso,27)<<4));
      biquad_dsp(&bs,&bc,inlet_in,outlet_out);

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
        if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 1)) {
            PExParameterChange(&parent->PExch[PARAM_INDEX_hp__1_pitch],(data2!=127)?(data2-64)<<21:0x07FFFFFF, 0xFFFD);
        }
}
}
}
;class instancemix__3{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancemix__3_gain1;
KeyValuePair KVP_instancemix__3_gain2;
  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_mix__3_gain1].pfunction = pfun_signed_clamp_fullrange_squarelaw;
  SetKVP_IPVP(&KVP_instancemix__3_gain1,ObjectKvpRoot, "mix_3:gain1" ,&parent->PExch[PARAM_INDEX_mix__3_gain1], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancemix__3_gain1);
parent->PExch[PARAM_INDEX_mix__3_gain2].pfunction = pfun_signed_clamp_fullrange_squarelaw;
  SetKVP_IPVP(&KVP_instancemix__3_gain2,ObjectKvpRoot, "mix_3:gain2" ,&parent->PExch[PARAM_INDEX_mix__3_gain2], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancemix__3_gain2);
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_bus__in,
const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
int32buffer  & outlet_out,
int param_gain1,
int param_gain2  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   int32_t accum = ___SMMUL(inlet_in1[buffer_index],param_gain1);
   accum = ___SMMLA(inlet_in2[buffer_index],param_gain2,accum);
;   outlet_out[buffer_index]=  __SSAT(inlet_bus__in[buffer_index] + (accum<<1),28);

}
}
}
;class instanceout__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent,
int32_t & disp_vuLeft,
int32_t & disp_vuRight) {
parent = _parent;
disp_vuLeft = 0;
disp_vuRight = 0;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_left,
const int32buffer  inlet_right,
int32_t & disp_vuLeft,
int32_t & disp_vuRight  ){
int j;
for(j=0;j<BUFSIZE;j++){
   AudioOutputLeft[j] += __SSAT(inlet_left[j],28);
   AudioOutputRight[j] += __SSAT(inlet_right[j],28);
}
disp_vuLeft=inlet_left[0];
disp_vuRight=inlet_right[0];

}
}
;class instancexfade__2{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_i1,
const int32buffer  inlet_i2,
const int32_t  inlet_c,
int32buffer  & outlet_o  ){
   int32_t ccompl = ((128<<20)-inlet_c);

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   {
      int64_t a = (int64_t)inlet_i2[buffer_index] * inlet_c;
      a += (int64_t)inlet_i1[buffer_index] * ccompl;
      outlet_o[buffer_index]= a>>27;
   }

}
}
}
;class instanceschmitttrigger__2{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instanceschmitttrigger__2_hysteresis;
  static const int blepvoices = 8;
  int16_t *oscp[blepvoices];
  uint32_t nextvoice;
  int32_t i0;

  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_schmitttrigger__2_hysteresis].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instanceschmitttrigger__2_hysteresis,ObjectKvpRoot, "schmitttrigger_2" ,&parent->PExch[PARAM_INDEX_schmitttrigger__2_hysteresis], 0, 1<<27);
  KVP_RegisterObject(&KVP_instanceschmitttrigger__2_hysteresis);
    int j;
    for(j=0;j<blepvoices;j++)
      oscp[j] = &blept[BLEPSIZE-1];
   nextvoice = 0;
   i0 = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
int32buffer  & outlet_out,
int param_hysteresis  ){
  int j;
  int16_t *lastblep = &blept[BLEPSIZE-1];
  for(j=0;j<BUFSIZE;j++){
    int i;
    int i1 = inlet_in[j]>>2;
    i1 += (nextvoice&1)?param_hysteresis:-param_hysteresis;
    int32_t sum=0;
    if ((i1>0)&&!(i0>0)){   // dispatch
      nextvoice = (nextvoice+1)&(blepvoices-1);
      int32_t x = 64-((-i0<<6)/(i1-i0));
      oscp[nextvoice] = &blept[x];
    } else if ((i1<0)&&!(i0<0)){   // dispatch
      nextvoice = (nextvoice+1)&(blepvoices-1);
      int32_t x = 64-((i0<<6)/(i0-i1));
      oscp[nextvoice] = &blept[x];
    }
    i0 = i1;
    for(i=0;i<blepvoices;i++){ // sample
      int16_t *t = oscp[i];
      if (i&1) sum+=*t; else sum-=*t; 
      t+=64;
      if (t>=lastblep) t=lastblep;
      oscp[i]=t;
    }
    sum -= ((((nextvoice+1)&1)<<1)-1)<<13;
    outlet_out[j]=sum<<13;
  }
}
}
;class instancevca__2{
  public: // v1
  rootc *parent;
   int32_t prev;
    int32_t step;

  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instancemix__2{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancemix__2_gain1;
KeyValuePair KVP_instancemix__2_gain2;
  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_mix__2_gain1].pfunction = pfun_signed_clamp_fullrange_squarelaw;
  SetKVP_IPVP(&KVP_instancemix__2_gain1,ObjectKvpRoot, "mix_2:gain1" ,&parent->PExch[PARAM_INDEX_mix__2_gain1], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancemix__2_gain1);
parent->PExch[PARAM_INDEX_mix__2_gain2].pfunction = pfun_signed_clamp_fullrange_squarelaw;
  SetKVP_IPVP(&KVP_instancemix__2_gain2,ObjectKvpRoot, "mix_2:gain2" ,&parent->PExch[PARAM_INDEX_mix__2_gain2], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancemix__2_gain2);
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_bus__in,
const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
int32buffer  & outlet_out,
int param_gain1,
int param_gain2  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   int32_t accum = ___SMMUL(inlet_in1[buffer_index],param_gain1);
   accum = ___SMMLA(inlet_in2[buffer_index],param_gain2,accum);
;   outlet_out[buffer_index]=  __SSAT(inlet_bus__in[buffer_index] + (accum<<1),28);

}
}
}
;class instancein__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent,
int32_t & disp_vuLeft,
int32_t & disp_vuRight) {
parent = _parent;
disp_vuLeft = 0;
disp_vuRight = 0;
}
  public: void Dispose() {
}
  public: void dsp (int32buffer  & outlet_left,
int32buffer  & outlet_right,
int32_t & disp_vuLeft,
int32_t & disp_vuRight  ){
int j;
for(j=0;j<BUFSIZE;j++){
   outlet_left[j] = AudioInputLeft[j];
   outlet_right[j] = AudioInputRight[j];
}
disp_vuLeft=outlet_left[0];
disp_vuRight=outlet_right[0];

}
}
;class instancec__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t & outlet_o  ){
outlet_o= 16;

}
}
;class instancehp__2{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancehp__2_pitch;
KeyValuePair KVP_instancehp__2_reso;
biquad_state bs;biquad_coefficients bc;

  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_hp__2_pitch].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancehp__2_pitch,ObjectKvpRoot, "hp_2:pitch" ,&parent->PExch[PARAM_INDEX_hp__2_pitch], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancehp__2_pitch);
parent->PExch[PARAM_INDEX_hp__2_reso].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancehp__2_reso,ObjectKvpRoot, "hp_2:reso" ,&parent->PExch[PARAM_INDEX_hp__2_reso], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancehp__2_reso);
biquad_clearstate(&bs);

}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
const int32_t  inlet_pitch,
const int32_t  inlet_reso,
int32buffer  & outlet_out,
int param_pitch,
int param_reso  ){
      int32_t freq;
      MTOF(param_pitch + inlet_pitch,freq);
      biquad_hp_coefs(&bc,freq,INT_MAX - (__USAT(inlet_reso + param_reso,27)<<4));
      biquad_dsp(&bs,&bc,inlet_in,outlet_out);

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
        if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 1)) {
            PExParameterChange(&parent->PExch[PARAM_INDEX_hp__2_pitch],(data2!=127)?(data2-64)<<21:0x07FFFFFF, 0xFFFD);
        }
}
}
}
;class instancemix__4{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancemix__4_gain1;
KeyValuePair KVP_instancemix__4_gain2;
  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_mix__4_gain1].pfunction = pfun_signed_clamp_fullrange_squarelaw;
  SetKVP_IPVP(&KVP_instancemix__4_gain1,ObjectKvpRoot, "mix_4:gain1" ,&parent->PExch[PARAM_INDEX_mix__4_gain1], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancemix__4_gain1);
parent->PExch[PARAM_INDEX_mix__4_gain2].pfunction = pfun_signed_clamp_fullrange_squarelaw;
  SetKVP_IPVP(&KVP_instancemix__4_gain2,ObjectKvpRoot, "mix_4:gain2" ,&parent->PExch[PARAM_INDEX_mix__4_gain2], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancemix__4_gain2);
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_bus__in,
const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
int32buffer  & outlet_out,
int param_gain1,
int param_gain2  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   int32_t accum = ___SMMUL(inlet_in1[buffer_index],param_gain1);
   accum = ___SMMLA(inlet_in2[buffer_index],param_gain2,accum);
;   outlet_out[buffer_index]=  __SSAT(inlet_bus__in[buffer_index] + (accum<<1),28);

}
}
}
;class instance_dash___1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in1,
const int32_t  inlet_in2,
int32_t  & outlet_out  ){
outlet_out= inlet_in1-inlet_in2 ;
}
}
;class instancediv__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out  ){
outlet_out= inlet_in>>4;
}
}
;class instancedial__2{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancedial__2_value;
  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_dial__2_value].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancedial__2_value,ObjectKvpRoot, "dial_2" ,&parent->PExch[PARAM_INDEX_dial__2_value], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancedial__2_value);
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out,
int param_value  ){
outlet_out= param_value;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
        if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 4)) {
            PExParameterChange(&parent->PExch[PARAM_INDEX_dial__2_value],(data2!=127)?data2<<20:0x07FFFFFF, 0xFFFD);
        }
}
}
}
;class instanceNoiseGate__2{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instanceNoiseGate__2_Pre;
KeyValuePair KVP_instanceNoiseGate__2_smooth2__1_colon_risetime;
KeyValuePair KVP_instanceNoiseGate__2_smooth2__1_colon_falltime;
KeyValuePair KVP_instanceNoiseGate__2_a_slash_d_colon_a;
KeyValuePair KVP_instanceNoiseGate__2_a_slash_d_colon_d;
KeyValuePair KVP_instanceNoiseGate__2_Threshold;
    static const uint32_t NPEXCH = 6;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_Pre_value = 0;
static const int PARAM_INDEX_smooth2__1_risetime = 1;
static const int PARAM_INDEX_smooth2__1_falltime = 2;
static const int PARAM_INDEX_a_slash_d_a = 3;
static const int PARAM_INDEX_a_slash_d_d = 4;
static const int PARAM_INDEX_Threshold_value = 5;
/* controller classes */
/* object classes */
class instancePre{
  public: // v1
  instanceNoiseGate__2 *parent;
KeyValuePair KVP_instancePre_value;
  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_Pre_value].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancePre_value,ObjectKvpRoot, "Pre" ,&parent->PExch[PARAM_INDEX_Pre_value], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancePre_value);
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out,
int param_value  ){
outlet_out= param_value;

}
}
;class instance_star___2{
  public: // v1
  instanceNoiseGate__2 *parent;
  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_a,
const int32buffer  inlet_b,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= ___SMMUL(inlet_a<<3,inlet_b[buffer_index]<<2);

}
}
}
;class instancemuls__1{
  public: // v1
  instanceNoiseGate__2 *parent;
  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
int32buffer  & outlet_out  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_out[buffer_index]= __SSAT(inlet_in[buffer_index],25)<<3;
}
}
}
;class instancefollower__1{
  public: // v1
  instanceNoiseGate__2 *parent;
int32_t accu;

  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
accu = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
int32_t  & outlet_amp  ){
 int sabs = 0;
int i;  for(i=0;i<BUFSIZE;i++){    int32_t v = inlet_in[i];
    sabs += v>0?v:-v;
  }
  accu -= accu>>5;
  accu += sabs>>(5+4);
  outlet_amp = accu;

}
}
;class instancesmooth2__1{
  public: // v1
  instanceNoiseGate__2 *parent;
KeyValuePair KVP_instancesmooth2__1_risetime;
KeyValuePair KVP_instancesmooth2__1_falltime;
int32_t val;

  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_smooth2__1_risetime].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancesmooth2__1_risetime,ObjectKvpRoot, "smooth2_1:risetime" ,&parent->PExch[PARAM_INDEX_smooth2__1_risetime], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancesmooth2__1_risetime);
parent->PExch[PARAM_INDEX_smooth2__1_falltime].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancesmooth2__1_falltime,ObjectKvpRoot, "smooth2_1:falltime" ,&parent->PExch[PARAM_INDEX_smooth2__1_falltime], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancesmooth2__1_falltime);
   val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_risetime,
int param_falltime  ){
   if (inlet_in>val)      val = ___SMMLA(val-inlet_in, (-1<<26)+(param_risetime>>1),val);
      else val = ___SMMLA(val-inlet_in,(-1<<26)+(param_falltime>>1),val);
   outlet_out = val;

}
}
;class instance_eq__eq___1{
  public: // v1
  instanceNoiseGate__2 *parent;
  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in1,
const int32_t  inlet_in2,
bool  & outlet_out  ){
outlet_out= inlet_in1>inlet_in2 ;
}
}
;class instanceInput{
  public: // v1
  instanceNoiseGate__2 *parent;
int32buffer _inlet;

  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32buffer  & outlet_inlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_inlet[buffer_index] = _inlet[buffer_index];
}
}
}
;class instancea_slash_d{
  public: // v1
  instanceNoiseGate__2 *parent;
KeyValuePair KVP_instancea_slash_d_a;
KeyValuePair KVP_instancea_slash_d_d;
int32_t val;

  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a_slash_d_a].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancea_slash_d_a,ObjectKvpRoot, "a/d:a" ,&parent->PExch[PARAM_INDEX_a_slash_d_a], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancea_slash_d_a);
parent->PExch[PARAM_INDEX_a_slash_d_d].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancea_slash_d_d,ObjectKvpRoot, "a/d:d" ,&parent->PExch[PARAM_INDEX_a_slash_d_d], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancea_slash_d_d);
val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_a,
const int32_t  inlet_d,
int32_t  & outlet_env,
int param_a,
int param_d  ){
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_a + inlet_a;
  MTOF(-at,t);
  val += t>>6;
}
else {
  int32_t t;
  int32_t dt = param_d + inlet_d;
  MTOF(-dt,t);
  val -= t>>6;
}
val = __USAT(val,27);
outlet_env = val;

}
}
;class instanceThreshold{
  public: // v1
  instanceNoiseGate__2 *parent;
KeyValuePair KVP_instanceThreshold_value;
  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_Threshold_value].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instanceThreshold_value,ObjectKvpRoot, "Threshold" ,&parent->PExch[PARAM_INDEX_Threshold_value], 0, 1<<27);
  KVP_RegisterObject(&KVP_instanceThreshold_value);
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out,
int param_value  ){
outlet_out= param_value;

}
}
;class instancediv__1{
  public: // v1
  instanceNoiseGate__2 *parent;
  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out  ){
outlet_out= inlet_in >>1;
}
}
;class instance_star___1{
  public: // v1
  instanceNoiseGate__2 *parent;
  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_a,
const int32buffer  inlet_b,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= ___SMMUL(inlet_a<<3,inlet_b[buffer_index]<<2);

}
}
}
;class instanceOutput{
  public: // v1
  instanceNoiseGate__2 *parent;
int32buffer _outlet;

  public: void Init(instanceNoiseGate__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;/* controller instances */
/* object instances */
     instancePre instancePre_i;
     instance_star___2 instance_star___2_i;
     instancemuls__1 instancemuls__1_i;
     instancefollower__1 instancefollower__1_i;
     instancesmooth2__1 instancesmooth2__1_i;
     instance_eq__eq___1 instance_eq__eq___1_i;
     instanceInput instanceInput_i;
     instancea_slash_d instancea_slash_d_i;
     instanceThreshold instanceThreshold_i;
     instancediv__1 instancediv__1_i;
     instance_star___1 instance_star___1_i;
     instanceOutput instanceOutput_i;
/* net latches */
    int32_t  net6Latch;
    int32buffer  net10Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[6]= {
      134217728,
      0,
      0,
      -134217728,
      117440512,
      78643200
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
// on Parent: propagate Pre false NoiseGate__2Pre_value
parent->PExch[PARAM_INDEX_NoiseGate__2_Pre].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__2_Pre].finalvalue = (int32_t)(&(parent->instanceNoiseGate__2_i.PExch[instanceNoiseGate__2::PARAM_INDEX_Pre_value]));
// on Parent: propagate smooth2_1:risetime false NoiseGate__2smooth2__1_risetime
parent->PExch[PARAM_INDEX_NoiseGate__2_smooth2__1_colon_risetime].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__2_smooth2__1_colon_risetime].finalvalue = (int32_t)(&(parent->instanceNoiseGate__2_i.PExch[instanceNoiseGate__2::PARAM_INDEX_smooth2__1_risetime]));
// on Parent: propagate smooth2_1:falltime false NoiseGate__2smooth2__1_falltime
parent->PExch[PARAM_INDEX_NoiseGate__2_smooth2__1_colon_falltime].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__2_smooth2__1_colon_falltime].finalvalue = (int32_t)(&(parent->instanceNoiseGate__2_i.PExch[instanceNoiseGate__2::PARAM_INDEX_smooth2__1_falltime]));
// on Parent: propagate a/d:a false NoiseGate__2a_slash_d_a
parent->PExch[PARAM_INDEX_NoiseGate__2_a_slash_d_colon_a].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__2_a_slash_d_colon_a].finalvalue = (int32_t)(&(parent->instanceNoiseGate__2_i.PExch[instanceNoiseGate__2::PARAM_INDEX_a_slash_d_a]));
// on Parent: propagate a/d:d false NoiseGate__2a_slash_d_d
parent->PExch[PARAM_INDEX_NoiseGate__2_a_slash_d_colon_d].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__2_a_slash_d_colon_d].finalvalue = (int32_t)(&(parent->instanceNoiseGate__2_i.PExch[instanceNoiseGate__2::PARAM_INDEX_a_slash_d_d]));
// on Parent: propagate Threshold false NoiseGate__2Threshold_value
parent->PExch[PARAM_INDEX_NoiseGate__2_Threshold].pfunction = PropagateToSub;
parent->PExch[PARAM_INDEX_NoiseGate__2_Threshold].finalvalue = (int32_t)(&(parent->instanceNoiseGate__2_i.PExch[instanceNoiseGate__2::PARAM_INDEX_Threshold_value]));
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<6;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instancePre_i.Init(this );
   instance_star___2_i.Init(this );
   instancemuls__1_i.Init(this );
   instancefollower__1_i.Init(this );
   instancesmooth2__1_i.Init(this );
   instance_eq__eq___1_i.Init(this );
   instanceInput_i.Init(this );
   instancea_slash_d_i.Init(this );
   instanceThreshold_i.Init(this );
   instancediv__1_i.Init(this );
   instance_star___1_i.Init(this );
   instanceOutput_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instanceOutput_i.Dispose();
   instance_star___1_i.Dispose();
   instancediv__1_i.Dispose();
   instanceThreshold_i.Dispose();
   instancea_slash_d_i.Dispose();
   instanceInput_i.Dispose();
   instance_eq__eq___1_i.Dispose();
   instancesmooth2__1_i.Dispose();
   instancefollower__1_i.Dispose();
   instancemuls__1_i.Dispose();
   instance_star___2_i.Dispose();
   instancePre_i.Dispose();

}
  public: void dsp (const int32buffer  inlet_Input,
int32buffer  & outlet_Output  ){
int i; /*...*/
   for(i=0;i<BUFSIZE;i++) instanceInput_i._inlet[i] = inlet_Input[i];
//--------- <nets> -----------//
    int32buffer  net0;
    int32_t  net1;
    int32_t  net2;
    int32_t  net3;
    bool  net4;
    int32_t  net5;
    int32_t  net6;
    int32buffer  net7;
    int32_t  net8;
    int32buffer  net9;
    int32buffer  net10;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancePre_i.dsp(net8, PExch[PARAM_INDEX_Pre_value].finalvalue);
  instance_star___2_i.dsp(net8, net10Latch, net7);
  instancemuls__1_i.dsp(net7, net9);
  instancefollower__1_i.dsp(net9, net1);
  instancesmooth2__1_i.dsp(net1, net3, PExch[PARAM_INDEX_smooth2__1_risetime].finalvalue, PExch[PARAM_INDEX_smooth2__1_falltime].finalvalue);
  instance_eq__eq___1_i.dsp(net3, net6Latch, net4);
  instanceInput_i.dsp(net10);
  instancea_slash_d_i.dsp(net4, 0 , 0 , net5, PExch[PARAM_INDEX_a_slash_d_a].finalvalue, PExch[PARAM_INDEX_a_slash_d_d].finalvalue);
  instanceThreshold_i.dsp(net2, PExch[PARAM_INDEX_Threshold_value].finalvalue);
  instancediv__1_i.dsp(net2, net6);
  instance_star___1_i.dsp(net5, net9, net0);
  instanceOutput_i.dsp(net0);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net6Latch = net6;
   for(i=0;i<BUFSIZE;i++)
      net10Latch[i]=net10[i];
//--------- </net latch copy> ----------//
      for(i=0;i<BUFSIZE;i++) outlet_Output[i] = instanceOutput_i._outlet[i];

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
}
}
}
;class instance_star___3{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_a,
const int32buffer  inlet_b,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= ___SMMUL(inlet_a<<3,inlet_b[buffer_index]<<2);

}
}
}
;class instanceSubOscillator__1{
  public: // v1
  rootc *parent;
    static const uint32_t NPEXCH = 1;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_sine__1_pitch = 0;
/* controller classes */
/* object classes */
class instanceSubOscOut{
  public: // v1
  instanceSubOscillator__1 *parent;
int32buffer _outlet;

  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;class instance_plus___1{
  public: // v1
  instanceSubOscillator__1 *parent;
  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_i1,
const int32_t  inlet_i2,
const bool  inlet_s,
int32_t  & outlet_o  ){
   outlet_o= (inlet_s)?inlet_i2:inlet_i1;

}
}
;class instancesine__1{
  public: // v1
  instanceSubOscillator__1 *parent;
KeyValuePair KVP_instancesine__1_pitch;
uint32_t Phase;
  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_sine__1_pitch].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancesine__1_pitch,ObjectKvpRoot, "sine_1" ,&parent->PExch[PARAM_INDEX_sine__1_pitch], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancesine__1_pitch);
Phase = 0;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32buffer  inlet_freq,
const int32buffer  inlet_phase,
int32buffer  & outlet_wave,
int param_pitch  ){
   int32_t freq;
   MTOFEXTENDED(param_pitch + inlet_pitch,freq);

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
Phase += freq + inlet_freq[buffer_index];
int32_t r;
int32_t p2 = Phase + (inlet_phase[buffer_index]<<4);
SINE2TINTERP(p2,r)
outlet_wave[buffer_index]= (r>>4);

}
}
}
;class instancekeyb__2{
  public: // v1
  instanceSubOscillator__1 *parent;
int8_t _note;
uint8_t _gate;
uint8_t _velo;
uint8_t _rvelo;

  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
_gate = 0;
_note = 0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate<<27;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 6) && (data2)) {
  if ((data1 >= 0)&&(data1 <= 55)) {
    _velo = data2;
    _note = data1-64;
    _gate = 1;
  }
} else if (((status == MIDI_NOTE_ON + 6) && (!data2))||          (status == MIDI_NOTE_OFF + 6)) {
  if (_note == data1-64) {
    _rvelo = data2;
    _gate = 0;
  }
} else if ((status == 6 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
   _gate = 0;
}
}
}
}
;class instancediv__1{
  public: // v1
  instanceSubOscillator__1 *parent;
  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in1,
const int32_t  inlet_in2,
int32_t  & outlet_out  ){
outlet_out= inlet_in1-inlet_in2 ;
}
}
;class instancei__1{
  public: // v1
  instanceSubOscillator__1 *parent;
  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t & outlet_out  ){
outlet_out= 12;

}
}
;class instancekeyb__1{
  public: // v1
  instanceSubOscillator__1 *parent;
int8_t _note;
uint8_t _gate;
uint8_t _velo;
uint8_t _rvelo;

  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
_gate = 0;
_note = 0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate<<27;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 6) && (data2)) {
  if ((data1 >= 56)&&(data1 <= 127)) {
    _velo = data2;
    _note = data1-64;
    _gate = 1;
  }
} else if (((status == MIDI_NOTE_ON + 6) && (!data2))||          (status == MIDI_NOTE_OFF + 6)) {
  if (_note == data1-64) {
    _rvelo = data2;
    _gate = 0;
  }
} else if ((status == 6 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
   _gate = 0;
}
}
}
}
;class instanceGateOut{
  public: // v1
  instanceSubOscillator__1 *parent;
int32_t _outlet;

  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_outlet  ){
  _outlet = inlet_outlet;

}
}
;class instance_plus___2{
  public: // v1
  instanceSubOscillator__1 *parent;
  public: void Init(instanceSubOscillator__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in1,
const int32_t  inlet_in2,
int32_t  & outlet_out  ){
outlet_out= inlet_in1+inlet_in2 ;
}
}
;/* controller instances */
/* object instances */
     instanceSubOscOut instanceSubOscOut_i;
     instance_plus___1 instance_plus___1_i;
     instancesine__1 instancesine__1_i;
     instancekeyb__2 instancekeyb__2_i;
     instancediv__1 instancediv__1_i;
     instancei__1 instancei__1_i;
     instancekeyb__1 instancekeyb__1_i;
     instanceGateOut instanceGateOut_i;
     instance_plus___2 instance_plus___2_i;
/* net latches */
    bool  net0Latch;
    int32_t  net1Latch;
    int32_t net2Latch;
    int32_t  net3Latch;
    int32_t  net5Latch;
    int32buffer  net6Latch;
    int32_t  net7Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[1]= {
      -24956108
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<1;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instanceSubOscOut_i.Init(this );
   instance_plus___1_i.Init(this );
   instancesine__1_i.Init(this );
   instancekeyb__2_i.Init(this );
   instancediv__1_i.Init(this );
   instancei__1_i.Init(this );
   instancekeyb__1_i.Init(this );
   instanceGateOut_i.Init(this );
   instance_plus___2_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instance_plus___2_i.Dispose();
   instanceGateOut_i.Dispose();
   instancekeyb__1_i.Dispose();
   instancei__1_i.Dispose();
   instancediv__1_i.Dispose();
   instancekeyb__2_i.Dispose();
   instancesine__1_i.Dispose();
   instance_plus___1_i.Dispose();
   instanceSubOscOut_i.Dispose();

}
  public: void dsp (int32buffer  & outlet_SubOscOut,
bool  & outlet_GateOut  ){
int i; /*...*/
//--------- <nets> -----------//
    bool  net0;
    int32_t  net1;
    int32_t net2;
    int32_t  net3;
    int32_t  net4;
    int32_t  net5;
    int32buffer  net6;
    int32_t  net7;
    bool  net8;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instanceSubOscOut_i.dsp(net6Latch);
  instance_plus___1_i.dsp(net5Latch, net3Latch, net0Latch, net4);
  instancesine__1_i.dsp(net4, zerobuffer, zerobuffer, net6, PExch[PARAM_INDEX_sine__1_pitch].finalvalue);
  instancekeyb__2_i.dsp(net5, net8, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instancediv__1_i.dsp(net1Latch, (net2Latch<<21), net3);
  instancei__1_i.dsp(net2);
  instancekeyb__1_i.dsp(net1, net0, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instanceGateOut_i.dsp((net7Latch>0));
  instance_plus___2_i.dsp((net8?(1<<27)-1:0), (net0?(1<<27)-1:0), net7);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net0Latch = net0;
net1Latch = net1;
net2Latch = net2;
net3Latch = net3;
net5Latch = net5;
   for(i=0;i<BUFSIZE;i++)
      net6Latch[i]=net6[i];
net7Latch = net7;
//--------- </net latch copy> ----------//
      for(i=0;i<BUFSIZE;i++) outlet_SubOscOut[i] = instanceSubOscOut_i._outlet[i];
   outlet_GateOut = instanceGateOut_i._outlet;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
instancekeyb__2_i.MidiInHandler(dev, port, status, data1, data2);
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
}
}
}
;class instance_plus___1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
int32buffer  & outlet_out  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_out[buffer_index]= inlet_in1[buffer_index]+inlet_in2[buffer_index] ;
}
}
}
;class instance_star___4{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_a,
const int32_t  inlet_b,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= ___SMMUL(inlet_a[buffer_index]<<3,inlet_b<<2);

}
}
}
;class instanceanalog__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out  ){
outlet_out= adcvalues[10]<<15;
}
}
;class instanceAD__to__int__1{
  public: // v1
  rootc *parent;
    static const uint32_t NPEXCH = 1;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_bipolar2unipolar__1_freq = 0;
/* controller classes */
/* object classes */
class instancemuls__1{
  public: // v1
  instanceAD__to__int__1 *parent;
  public: void Init(instanceAD__to__int__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out  ){
outlet_out= inlet_in<<1;
}
}
;class instanceAD__in{
  public: // v1
  instanceAD__to__int__1 *parent;
int32_t _inlet;

  public: void Init(instanceAD__to__int__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_inlet  ){
  outlet_inlet = _inlet;

}
}
;class instancebipolar2unipolar__1{
  public: // v1
  instanceAD__to__int__1 *parent;
KeyValuePair KVP_instancebipolar2unipolar__1_freq;
int32_t val;

  public: void Init(instanceAD__to__int__1 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_bipolar2unipolar__1_freq].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancebipolar2unipolar__1_freq,ObjectKvpRoot, "bipolar2unipolar_1" ,&parent->PExch[PARAM_INDEX_bipolar2unipolar__1_freq], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancebipolar2unipolar__1_freq);
val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_freq  ){
int32_t f;
   MTOF(param_freq,f);
   val = ___SMMLA((inlet_in-val)<<1,f,val);
   outlet_out= val;

}
}
;class instanceto__1{
  public: // v1
  instanceAD__to__int__1 *parent;
  public: void Init(instanceAD__to__int__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t inlet_i,
int32_t & outlet_o  ){
   outlet_o= inlet_i;

}
}
;class instanceOut{
  public: // v1
  instanceAD__to__int__1 *parent;
int32_t _outlet;

  public: void Init(instanceAD__to__int__1 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t inlet_outlet  ){
  _outlet = inlet_outlet;

}
}
;/* controller instances */
/* object instances */
     instancemuls__1 instancemuls__1_i;
     instanceAD__in instanceAD__in_i;
     instancebipolar2unipolar__1 instancebipolar2unipolar__1_i;
     instanceto__1 instanceto__1_i;
     instanceOut instanceOut_i;
/* net latches */
    int32_t  net0Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[1]= {
      -6291456
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<1;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instancemuls__1_i.Init(this );
   instanceAD__in_i.Init(this );
   instancebipolar2unipolar__1_i.Init(this );
   instanceto__1_i.Init(this );
   instanceOut_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instanceOut_i.Dispose();
   instanceto__1_i.Dispose();
   instancebipolar2unipolar__1_i.Dispose();
   instanceAD__in_i.Dispose();
   instancemuls__1_i.Dispose();

}
  public: void dsp (const int32_t  inlet_AD__in,
int32_t & outlet_Out  ){
int i; /*...*/
   instanceAD__in_i._inlet = inlet_AD__in;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t net1;
    int32_t  net2;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancemuls__1_i.dsp(net0Latch, UNCONNECTED_OUTPUT);
  instanceAD__in_i.dsp(net2);
  instancebipolar2unipolar__1_i.dsp(net2, net0, PExch[PARAM_INDEX_bipolar2unipolar__1_freq].finalvalue);
  instanceto__1_i.dsp((net0>>21), net1);
  instanceOut_i.dsp(net1);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net0Latch = net0;
//--------- </net latch copy> ----------//
   outlet_Out = instanceOut_i._outlet;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
}
}
}
;class instanceLFilter_space_Pitch{
  public: // v1
  rootc *parent;
int32_t lsend;
int timer;

  public: void Init(rootc * _parent) {
parent = _parent;
timer = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v  ){
if (((lsend>inlet_v+(1<<19))||(inlet_v>lsend+(1<<19))) && (timer>30)) {
   lsend = inlet_v;
   PatchMidiInHandler(MIDI_DEVICE_INTERNAL ,0,MIDI_CONTROL_CHANGE + (1-1),1,__USAT(inlet_v>>20,7));
   timer = 0;
} else timer++;

}
}
;class instancedial__1{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancedial__1_value;
  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_dial__1_value].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancedial__1_value,ObjectKvpRoot, "dial_1" ,&parent->PExch[PARAM_INDEX_dial__1_value], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancedial__1_value);
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out,
int param_value  ){
outlet_out= param_value;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
        if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 2)) {
            PExParameterChange(&parent->PExch[PARAM_INDEX_dial__1_value],(data2!=127)?data2<<20:0x07FFFFFF, 0xFFFD);
        }
}
}
}
;class instancead__1{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancead__1_a;
KeyValuePair KVP_instancead__1_d;
KeyValuePair KVP_instancead__1_s;
KeyValuePair KVP_instancead__1_r;
int8_t stage;
int ntrig;
int32_t val;

  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_ad__1_a].pfunction = pfun_kexpltime;
  SetKVP_IPVP(&KVP_instancead__1_a,ObjectKvpRoot, "ad_1:a" ,&parent->PExch[PARAM_INDEX_ad__1_a], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancead__1_a);
parent->PExch[PARAM_INDEX_ad__1_d].pfunction = pfun_kexpdtime;
  SetKVP_IPVP(&KVP_instancead__1_d,ObjectKvpRoot, "ad_1:d" ,&parent->PExch[PARAM_INDEX_ad__1_d], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancead__1_d);
parent->PExch[PARAM_INDEX_ad__1_s].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancead__1_s,ObjectKvpRoot, "ad_1:s" ,&parent->PExch[PARAM_INDEX_ad__1_s], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancead__1_s);
parent->PExch[PARAM_INDEX_ad__1_r].pfunction = pfun_kexpdtime;
  SetKVP_IPVP(&KVP_instancead__1_r,ObjectKvpRoot, "ad_1:r" ,&parent->PExch[PARAM_INDEX_ad__1_r], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancead__1_r);
stage = 0;
ntrig = 0;
val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_gate,
int32_t  & outlet_env,
int param_a,
int param_d,
int param_s,
int param_r  ){
if ((inlet_gate>0) && !ntrig) {
   stage = 1;
   ntrig = 1;
}
if (!(inlet_gate>0) && ntrig) {
   stage = 0;
   ntrig=0;
}
if (stage == 0){
   val = ___SMMUL(val,param_r)<<1;
} else if (stage == 1){
   val = val + param_a;
   if (val<0) {
      val =0x7FFFFFFF;
      stage = 2;
   }
} else if (stage == 2) {
   val = (param_s<<4) + (___SMMUL(val - (param_s<<4),param_d)<<1);
}

outlet_env = val>>4;
}
}
;class instanceanalog__2{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out  ){
outlet_out= adcvalues[11]<<15;
}
}
;class instanceAD__to__int__2{
  public: // v1
  rootc *parent;
    static const uint32_t NPEXCH = 1;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_bipolar2unipolar__1_freq = 0;
/* controller classes */
/* object classes */
class instancemuls__1{
  public: // v1
  instanceAD__to__int__2 *parent;
  public: void Init(instanceAD__to__int__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out  ){
outlet_out= inlet_in<<1;
}
}
;class instanceAD__in{
  public: // v1
  instanceAD__to__int__2 *parent;
int32_t _inlet;

  public: void Init(instanceAD__to__int__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_inlet  ){
  outlet_inlet = _inlet;

}
}
;class instancebipolar2unipolar__1{
  public: // v1
  instanceAD__to__int__2 *parent;
KeyValuePair KVP_instancebipolar2unipolar__1_freq;
int32_t val;

  public: void Init(instanceAD__to__int__2 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_bipolar2unipolar__1_freq].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancebipolar2unipolar__1_freq,ObjectKvpRoot, "bipolar2unipolar_1" ,&parent->PExch[PARAM_INDEX_bipolar2unipolar__1_freq], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancebipolar2unipolar__1_freq);
val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_freq  ){
int32_t f;
   MTOF(param_freq,f);
   val = ___SMMLA((inlet_in-val)<<1,f,val);
   outlet_out= val;

}
}
;class instanceto__1{
  public: // v1
  instanceAD__to__int__2 *parent;
  public: void Init(instanceAD__to__int__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t inlet_i,
int32_t & outlet_o  ){
   outlet_o= inlet_i;

}
}
;class instanceOut{
  public: // v1
  instanceAD__to__int__2 *parent;
int32_t _outlet;

  public: void Init(instanceAD__to__int__2 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t inlet_outlet  ){
  _outlet = inlet_outlet;

}
}
;/* controller instances */
/* object instances */
     instancemuls__1 instancemuls__1_i;
     instanceAD__in instanceAD__in_i;
     instancebipolar2unipolar__1 instancebipolar2unipolar__1_i;
     instanceto__1 instanceto__1_i;
     instanceOut instanceOut_i;
/* net latches */
    int32_t  net0Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[1]= {
      -6291456
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<1;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instancemuls__1_i.Init(this );
   instanceAD__in_i.Init(this );
   instancebipolar2unipolar__1_i.Init(this );
   instanceto__1_i.Init(this );
   instanceOut_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instanceOut_i.Dispose();
   instanceto__1_i.Dispose();
   instancebipolar2unipolar__1_i.Dispose();
   instanceAD__in_i.Dispose();
   instancemuls__1_i.Dispose();

}
  public: void dsp (const int32_t  inlet_AD__in,
int32_t & outlet_Out  ){
int i; /*...*/
   instanceAD__in_i._inlet = inlet_AD__in;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t net1;
    int32_t  net2;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancemuls__1_i.dsp(net0Latch, UNCONNECTED_OUTPUT);
  instanceAD__in_i.dsp(net2);
  instancebipolar2unipolar__1_i.dsp(net2, net0, PExch[PARAM_INDEX_bipolar2unipolar__1_freq].finalvalue);
  instanceto__1_i.dsp((net0>>21), net1);
  instanceOut_i.dsp(net1);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net0Latch = net0;
//--------- </net latch copy> ----------//
   outlet_Out = instanceOut_i._outlet;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
}
}
}
;class instanceSubOsc{
  public: // v1
  rootc *parent;
int32_t lsend;
int timer;

  public: void Init(rootc * _parent) {
parent = _parent;
timer = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v  ){
if (((lsend>inlet_v+(1<<19))||(inlet_v>lsend+(1<<19))) && (timer>30)) {
   lsend = inlet_v;
   PatchMidiInHandler(MIDI_DEVICE_INTERNAL ,0,MIDI_CONTROL_CHANGE + (1-1),2,__USAT(inlet_v>>20,7));
   timer = 0;
} else timer++;

}
}
;class instancelp__1{
  public: // v1
  rootc *parent;
KeyValuePair KVP_instancelp__1_pitch;
KeyValuePair KVP_instancelp__1_reso;
int32_t low;
int32_t band;

  public: void Init(rootc * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_lp__1_pitch].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancelp__1_pitch,ObjectKvpRoot, "lp_1:pitch" ,&parent->PExch[PARAM_INDEX_lp__1_pitch], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancelp__1_pitch);
parent->PExch[PARAM_INDEX_lp__1_reso].pfunction = pfun_unsigned_clamp;
  SetKVP_IPVP(&KVP_instancelp__1_reso,ObjectKvpRoot, "lp_1:reso" ,&parent->PExch[PARAM_INDEX_lp__1_reso], 0, 1<<27);
  KVP_RegisterObject(&KVP_instancelp__1_reso);
low = 0;
band = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_pitch,
int param_reso  ){
int32_t damp = (0x80<<24) - (param_reso<<4);
damp = ___SMMUL(damp,damp);
int32_t alpha;
int32_t freq;
MTOFEXTENDED(param_pitch,alpha);
SINE2TINTERP(alpha,freq);
int32_t in1 = inlet_in;
int32_t notch = inlet_in - (___SMMUL(damp,band)<<1);
low = low + (___SMMUL(freq,band)<<1);
int32_t high  = notch - low;
band = (___SMMUL(freq,high)<<1) + band;// - drive*band*band*band;
int32_t out1 = low;
outlet_out = out1;

}
}
;class instancemidithru__1{
  public: // v1
  rootc *parent;
int 		flash_cnt=0;
bool 	flash_state = false;
const int FLASH_LEN = 0x100;
  public: void Init(rootc * _parent) {
parent = _parent;
if(true) {
        sysmon_disable_blinker();
        palSetPadMode(LED2_PORT,LED2_PIN,PAL_MODE_OUTPUT_PUSHPULL);
}
flash_cnt = 0;
flash_state = false;
}
  public: void Dispose() {
}
  public: void dsp (  ){
if(true) {
	if(flash_cnt > 0) flash_cnt--;
	bool fs = flash_cnt > 0;
	if(fs!=flash_state) {
		palWritePad(LED2_PORT,LED2_PIN,fs);
		flash_state = fs;
	}
    }
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if(dev == MIDI_DEVICE_DIN && port == 1) 
{
    uint8_t status_type = status & 0xF0;

    switch (status)
    { 
    case MIDI_TIMING_CLOCK: 
    case MIDI_MEASURE_END:
    case MIDI_START:
    case MIDI_CONTINUE:
    case MIDI_STOP: 
        {
            MidiSend1((midi_device_t) MIDI_DEVICE_DIN, 1,status);
        }
    break;
    }

    switch (status_type)
    {
    case MIDI_CONTROL_CHANGE:
    case MIDI_NOTE_OFF:
    case MIDI_NOTE_ON:
    case MIDI_POLY_PRESSURE:
    case MIDI_PITCH_BEND: 
        {
            MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1,status,data1,data2);
            flash_cnt = FLASH_LEN;
        }
    break;

    case MIDI_PROGRAM_CHANGE:
    case MIDI_CHANNEL_PRESSURE: 
        {
            MidiSend2((midi_device_t) MIDI_DEVICE_DIN, 1,status,data1);
            flash_cnt = FLASH_LEN;
        }
    break;
    }
}}
}
}
;class instancemidithru__2{
  public: // v1
  rootc *parent;
int 		flash_cnt=0;
bool 	flash_state = false;
const int FLASH_LEN = 0x100;
  public: void Init(rootc * _parent) {
parent = _parent;
if(false) {
        sysmon_disable_blinker();
        palSetPadMode(LED2_PORT,LED2_PIN,PAL_MODE_OUTPUT_PUSHPULL);
}
flash_cnt = 0;
flash_state = false;
}
  public: void Dispose() {
}
  public: void dsp (  ){
if(false) {
	if(flash_cnt > 0) flash_cnt--;
	bool fs = flash_cnt > 0;
	if(fs!=flash_state) {
		palWritePad(LED2_PORT,LED2_PIN,fs);
		flash_state = fs;
	}
    }
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if(dev == MIDI_DEVICE_DIN && port == 1) 
{
    uint8_t status_type = status & 0xF0;

    switch (status)
    { 
    case MIDI_TIMING_CLOCK: 
    case MIDI_MEASURE_END:
    case MIDI_START:
    case MIDI_CONTINUE:
    case MIDI_STOP: 
        {
            MidiSend1((midi_device_t) MIDI_DEVICE_USB_DEVICE, 1,status);
        }
    break;
    }

    switch (status_type)
    {
    case MIDI_CONTROL_CHANGE:
    case MIDI_NOTE_OFF:
    case MIDI_NOTE_ON:
    case MIDI_POLY_PRESSURE:
    case MIDI_PITCH_BEND: 
        {
            MidiSend3((midi_device_t) MIDI_DEVICE_USB_DEVICE, 1,status,data1,data2);
            flash_cnt = FLASH_LEN;
        }
    break;

    case MIDI_PROGRAM_CHANGE:
    case MIDI_CHANNEL_PRESSURE: 
        {
            MidiSend2((midi_device_t) MIDI_DEVICE_USB_DEVICE, 1,status,data1);
            flash_cnt = FLASH_LEN;
        }
    break;
    }
}}
}
}
;class instanceanalog__3{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out  ){
outlet_out= adcvalues[12]<<15;
}
}
;class instanceAD__to__int__3{
  public: // v1
  rootc *parent;
    static const uint32_t NPEXCH = 1;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_bipolar2unipolar__1_freq = 0;
/* controller classes */
/* object classes */
class instancemuls__1{
  public: // v1
  instanceAD__to__int__3 *parent;
  public: void Init(instanceAD__to__int__3 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out  ){
outlet_out= inlet_in<<1;
}
}
;class instanceAD__in{
  public: // v1
  instanceAD__to__int__3 *parent;
int32_t _inlet;

  public: void Init(instanceAD__to__int__3 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_inlet  ){
  outlet_inlet = _inlet;

}
}
;class instancebipolar2unipolar__1{
  public: // v1
  instanceAD__to__int__3 *parent;
KeyValuePair KVP_instancebipolar2unipolar__1_freq;
int32_t val;

  public: void Init(instanceAD__to__int__3 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_bipolar2unipolar__1_freq].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancebipolar2unipolar__1_freq,ObjectKvpRoot, "bipolar2unipolar_1" ,&parent->PExch[PARAM_INDEX_bipolar2unipolar__1_freq], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancebipolar2unipolar__1_freq);
val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_freq  ){
int32_t f;
   MTOF(param_freq,f);
   val = ___SMMLA((inlet_in-val)<<1,f,val);
   outlet_out= val;

}
}
;class instanceto__1{
  public: // v1
  instanceAD__to__int__3 *parent;
  public: void Init(instanceAD__to__int__3 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t inlet_i,
int32_t & outlet_o  ){
   outlet_o= inlet_i;

}
}
;class instanceOut{
  public: // v1
  instanceAD__to__int__3 *parent;
int32_t _outlet;

  public: void Init(instanceAD__to__int__3 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t inlet_outlet  ){
  _outlet = inlet_outlet;

}
}
;/* controller instances */
/* object instances */
     instancemuls__1 instancemuls__1_i;
     instanceAD__in instanceAD__in_i;
     instancebipolar2unipolar__1 instancebipolar2unipolar__1_i;
     instanceto__1 instanceto__1_i;
     instanceOut instanceOut_i;
/* net latches */
    int32_t  net0Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[1]= {
      -6291456
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<1;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instancemuls__1_i.Init(this );
   instanceAD__in_i.Init(this );
   instancebipolar2unipolar__1_i.Init(this );
   instanceto__1_i.Init(this );
   instanceOut_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instanceOut_i.Dispose();
   instanceto__1_i.Dispose();
   instancebipolar2unipolar__1_i.Dispose();
   instanceAD__in_i.Dispose();
   instancemuls__1_i.Dispose();

}
  public: void dsp (const int32_t  inlet_AD__in,
int32_t & outlet_Out  ){
int i; /*...*/
   instanceAD__in_i._inlet = inlet_AD__in;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t net1;
    int32_t  net2;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancemuls__1_i.dsp(net0Latch, UNCONNECTED_OUTPUT);
  instanceAD__in_i.dsp(net2);
  instancebipolar2unipolar__1_i.dsp(net2, net0, PExch[PARAM_INDEX_bipolar2unipolar__1_freq].finalvalue);
  instanceto__1_i.dsp((net0>>21), net1);
  instanceOut_i.dsp(net1);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net0Latch = net0;
//--------- </net latch copy> ----------//
   outlet_Out = instanceOut_i._outlet;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
}
}
}
;class instanceSideCh{
  public: // v1
  rootc *parent;
int32_t lsend;
int timer;

  public: void Init(rootc * _parent) {
parent = _parent;
timer = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v  ){
if (((lsend>inlet_v+(1<<19))||(inlet_v>lsend+(1<<19))) && (timer>30)) {
   lsend = inlet_v;
   PatchMidiInHandler(MIDI_DEVICE_INTERNAL ,0,MIDI_CONTROL_CHANGE + (1-1),3,__USAT(inlet_v>>20,7));
   timer = 0;
} else timer++;

}
}
;class instanceanalog__4{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_out  ){
outlet_out= adcvalues[13]<<15;
}
}
;class instanceAD__to__int__4{
  public: // v1
  rootc *parent;
    static const uint32_t NPEXCH = 1;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 8;
    static const uint32_t NPRESET_ENTRIES = 32;
    static const uint32_t NMODULATIONSOURCES = 8;
    static const uint32_t NMODULATIONTARGETS = 8;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_bipolar2unipolar__1_freq = 0;
/* controller classes */
/* object classes */
class instancemuls__1{
  public: // v1
  instanceAD__to__int__4 *parent;
  public: void Init(instanceAD__to__int__4 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out  ){
outlet_out= inlet_in<<1;
}
}
;class instanceAD__in{
  public: // v1
  instanceAD__to__int__4 *parent;
int32_t _inlet;

  public: void Init(instanceAD__to__int__4 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_inlet  ){
  outlet_inlet = _inlet;

}
}
;class instancebipolar2unipolar__1{
  public: // v1
  instanceAD__to__int__4 *parent;
KeyValuePair KVP_instancebipolar2unipolar__1_freq;
int32_t val;

  public: void Init(instanceAD__to__int__4 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_bipolar2unipolar__1_freq].pfunction = pfun_signed_clamp;
  SetKVP_IPVP(&KVP_instancebipolar2unipolar__1_freq,ObjectKvpRoot, "bipolar2unipolar_1" ,&parent->PExch[PARAM_INDEX_bipolar2unipolar__1_freq], -1<<27, 1<<27);
  KVP_RegisterObject(&KVP_instancebipolar2unipolar__1_freq);
val = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_freq  ){
int32_t f;
   MTOF(param_freq,f);
   val = ___SMMLA((inlet_in-val)<<1,f,val);
   outlet_out= val;

}
}
;class instanceto__1{
  public: // v1
  instanceAD__to__int__4 *parent;
  public: void Init(instanceAD__to__int__4 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t inlet_i,
int32_t & outlet_o  ){
   outlet_o= inlet_i;

}
}
;class instanceOut{
  public: // v1
  instanceAD__to__int__4 *parent;
int32_t _outlet;

  public: void Init(instanceAD__to__int__4 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t inlet_outlet  ){
  _outlet = inlet_outlet;

}
}
;/* controller instances */
/* object instances */
     instancemuls__1 instancemuls__1_i;
     instanceAD__in instanceAD__in_i;
     instancebipolar2unipolar__1 instancebipolar2unipolar__1_i;
     instanceto__1 instanceto__1_i;
     instanceOut instanceOut_i;
/* net latches */
    int32_t  net0Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[1]= {
      -6291456
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<1;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instancemuls__1_i.Init(this );
   instanceAD__in_i.Init(this );
   instancebipolar2unipolar__1_i.Init(this );
   instanceto__1_i.Init(this );
   instanceOut_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instanceOut_i.Dispose();
   instanceto__1_i.Dispose();
   instancebipolar2unipolar__1_i.Dispose();
   instanceAD__in_i.Dispose();
   instancemuls__1_i.Dispose();

}
  public: void dsp (const int32_t  inlet_AD__in,
int32_t & outlet_Out  ){
int i; /*...*/
   instanceAD__in_i._inlet = inlet_AD__in;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t net1;
    int32_t  net2;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancemuls__1_i.dsp(net0Latch, UNCONNECTED_OUTPUT);
  instanceAD__in_i.dsp(net2);
  instancebipolar2unipolar__1_i.dsp(net2, net0, PExch[PARAM_INDEX_bipolar2unipolar__1_freq].finalvalue);
  instanceto__1_i.dsp((net0>>21), net1);
  instanceOut_i.dsp(net1);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net0Latch = net0;
//--------- </net latch copy> ----------//
   outlet_Out = instanceOut_i._outlet;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
}
}
}
;class instanceDist{
  public: // v1
  rootc *parent;
int32_t lsend;
int timer;

  public: void Init(rootc * _parent) {
parent = _parent;
timer = 0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v  ){
if (((lsend>inlet_v+(1<<19))||(inlet_v>lsend+(1<<19))) && (timer>30)) {
   lsend = inlet_v;
   PatchMidiInHandler(MIDI_DEVICE_INTERNAL ,0,MIDI_CONTROL_CHANGE + (1-1),4,__USAT(inlet_v>>20,7));
   timer = 0;
} else timer++;

}
}
;/* controller instances */
/* object instances */
     instanceoutconfig__1 instanceoutconfig__1_i;
     instanceKickEnv__1 instanceKickEnv__1_i;
     instance_star___2 instance_star___2_i;
     instancemix__1 instancemix__1_i;
     instanceschmitttrigger__1 instanceschmitttrigger__1_i;
     instancevca__1 instancevca__1_i;
     instancexfade__1 instancexfade__1_i;
     instance_star___1 instance_star___1_i;
     instanceNoiseGate__1 instanceNoiseGate__1_i;
     instancehp__1 instancehp__1_i;
     instancemix__3 instancemix__3_i;
     instanceout__1 instanceout__1_i;
     instancexfade__2 instancexfade__2_i;
     instanceschmitttrigger__2 instanceschmitttrigger__2_i;
     instancevca__2 instancevca__2_i;
     instancemix__2 instancemix__2_i;
     instancein__1 instancein__1_i;
     instancec__1 instancec__1_i;
     instancehp__2 instancehp__2_i;
     instancemix__4 instancemix__4_i;
     instance_dash___1 instance_dash___1_i;
     instancediv__1 instancediv__1_i;
     instancedial__2 instancedial__2_i;
     instanceNoiseGate__2 instanceNoiseGate__2_i;
     instance_star___3 instance_star___3_i;
     instanceSubOscillator__1 instanceSubOscillator__1_i;
     instance_plus___1 instance_plus___1_i;
     instance_star___4 instance_star___4_i;
     instanceanalog__1 instanceanalog__1_i;
     instanceAD__to__int__1 instanceAD__to__int__1_i;
     instanceLFilter_space_Pitch instanceLFilter_space_Pitch_i;
     instancedial__1 instancedial__1_i;
     instancead__1 instancead__1_i;
     instanceanalog__2 instanceanalog__2_i;
     instanceAD__to__int__2 instanceAD__to__int__2_i;
     instanceSubOsc instanceSubOsc_i;
     instancelp__1 instancelp__1_i;
     instancemidithru__1 instancemidithru__1_i;
     instancemidithru__2 instancemidithru__2_i;
     instanceanalog__3 instanceanalog__3_i;
     instanceAD__to__int__3 instanceAD__to__int__3_i;
     instanceSideCh instanceSideCh_i;
     instanceanalog__4 instanceanalog__4_i;
     instanceAD__to__int__4 instanceAD__to__int__4_i;
     instanceDist instanceDist_i;
/* net latches */
    int32buffer  net0Latch;
    int32buffer  net3Latch;
    int32buffer  net5Latch;
    int32buffer  net6Latch;
    int32_t  net9Latch;
    int32buffer  net24Latch;
    int32buffer  net25Latch;
    int32buffer  net26Latch;
    int32_t  net28Latch;
    int32_t  net31Latch;
    int32_t  net32Latch;
    int32_t  net34Latch;
    int32buffer  net36Latch;
    int32buffer  net37Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[35]= {
      132120576,
      134217728,
      133169152,
      1048576,
      8598323,
      0,
      0,
      -134217728,
      117440512,
      4194304,
      -62914560,
      0,
      134217728,
      0,
      1048576,
      134217728,
      134217728,
      -62914560,
      0,
      134217728,
      0,
      0,
      9646899,
      0,
      0,
      -134217728,
      117440512,
      4194304,
      83886080,
      -33554432,
      -25165824,
      132120576,
      -27262976,
      -94371840,
      0
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         },
         {
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0},
           {-1,0}
         }
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}},
{{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0},{-1,0}}};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };
/* init */
void Init() {
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<35;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 4;
   instanceoutconfig__1_i.Init(this );
   instanceKickEnv__1_i.Init(this );
   instance_star___2_i.Init(this );
   instancemix__1_i.Init(this );
   instanceschmitttrigger__1_i.Init(this );
   instancevca__1_i.Init(this );
   instancexfade__1_i.Init(this );
   instance_star___1_i.Init(this );
   instanceNoiseGate__1_i.Init(this );
   instancehp__1_i.Init(this );
   instancemix__3_i.Init(this );
   instanceout__1_i.Init(this, displayVector[3], displayVector[4] );
   instancexfade__2_i.Init(this );
   instanceschmitttrigger__2_i.Init(this );
   instancevca__2_i.Init(this );
   instancemix__2_i.Init(this );
   instancein__1_i.Init(this, displayVector[5], displayVector[6] );
   instancec__1_i.Init(this );
   instancehp__2_i.Init(this );
   instancemix__4_i.Init(this );
   instance_dash___1_i.Init(this );
   instancediv__1_i.Init(this );
   instancedial__2_i.Init(this );
   instanceNoiseGate__2_i.Init(this );
   instance_star___3_i.Init(this );
   instanceSubOscillator__1_i.Init(this );
   instance_plus___1_i.Init(this );
   instance_star___4_i.Init(this );
   instanceanalog__1_i.Init(this );
   instanceAD__to__int__1_i.Init(this );
   instanceLFilter_space_Pitch_i.Init(this );
   instancedial__1_i.Init(this );
   instancead__1_i.Init(this );
   instanceanalog__2_i.Init(this );
   instanceAD__to__int__2_i.Init(this );
   instanceSubOsc_i.Init(this );
   instancelp__1_i.Init(this );
   instancemidithru__1_i.Init(this );
   instancemidithru__2_i.Init(this );
   instanceanalog__3_i.Init(this );
   instanceAD__to__int__3_i.Init(this );
   instanceSideCh_i.Init(this );
   instanceanalog__4_i.Init(this );
   instanceAD__to__int__4_i.Init(this );
   instanceDist_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
}

/* dispose */
void Dispose() {
   instanceDist_i.Dispose();
   instanceAD__to__int__4_i.Dispose();
   instanceanalog__4_i.Dispose();
   instanceSideCh_i.Dispose();
   instanceAD__to__int__3_i.Dispose();
   instanceanalog__3_i.Dispose();
   instancemidithru__2_i.Dispose();
   instancemidithru__1_i.Dispose();
   instancelp__1_i.Dispose();
   instanceSubOsc_i.Dispose();
   instanceAD__to__int__2_i.Dispose();
   instanceanalog__2_i.Dispose();
   instancead__1_i.Dispose();
   instancedial__1_i.Dispose();
   instanceLFilter_space_Pitch_i.Dispose();
   instanceAD__to__int__1_i.Dispose();
   instanceanalog__1_i.Dispose();
   instance_star___4_i.Dispose();
   instance_plus___1_i.Dispose();
   instanceSubOscillator__1_i.Dispose();
   instance_star___3_i.Dispose();
   instanceNoiseGate__2_i.Dispose();
   instancedial__2_i.Dispose();
   instancediv__1_i.Dispose();
   instance_dash___1_i.Dispose();
   instancemix__4_i.Dispose();
   instancehp__2_i.Dispose();
   instancec__1_i.Dispose();
   instancein__1_i.Dispose();
   instancemix__2_i.Dispose();
   instancevca__2_i.Dispose();
   instanceschmitttrigger__2_i.Dispose();
   instancexfade__2_i.Dispose();
   instanceout__1_i.Dispose();
   instancemix__3_i.Dispose();
   instancehp__1_i.Dispose();
   instanceNoiseGate__1_i.Dispose();
   instance_star___1_i.Dispose();
   instancexfade__1_i.Dispose();
   instancevca__1_i.Dispose();
   instanceschmitttrigger__1_i.Dispose();
   instancemix__1_i.Dispose();
   instance_star___2_i.Dispose();
   instanceKickEnv__1_i.Dispose();
   instanceoutconfig__1_i.Dispose();
}

/* krate */
void dsp (void) {
  int i;
  for(i=0;i<BUFSIZE;i++) AudioOutputLeft[i]=0;
  for(i=0;i<BUFSIZE;i++) AudioOutputRight[i]=0;
//--------- <nets> -----------//
    int32buffer  net0;
    int32buffer  net1;
    int32buffer  net2;
    int32buffer  net3;
    int32buffer  net4;
    int32buffer  net5;
    int32buffer  net6;
    int32buffer  net7;
    int32buffer  net8;
    int32_t  net9;
    int32buffer  net10;
    int32buffer  net11;
    int32_t  net12;
    int32_t net13;
    int32_t  net14;
    int32_t net15;
    int32_t  net16;
    int32_t net17;
    int32_t  net18;
    int32_t net19;
    int32buffer  net20;
    bool  net21;
    int32buffer  net22;
    int32_t  net23;
    int32buffer  net24;
    int32buffer  net25;
    int32buffer  net26;
    int32_t  net27;
    int32_t  net28;
    int32buffer  net29;
    int32buffer  net30;
    int32_t  net31;
    int32_t  net32;
    int32_t net33;
    int32_t  net34;
    int32buffer  net35;
    int32buffer  net36;
    int32buffer  net37;
    int32buffer  net38;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instanceoutconfig__1_i.dsp();
  instanceKickEnv__1_i.dsp(net23);
  instance_star___2_i.dsp(net23, net25Latch, net7);
  instancemix__1_i.dsp(zerobuffer, net6Latch, net36Latch, net2, PExch[PARAM_INDEX_mix__1_gain1].finalvalue, PExch[PARAM_INDEX_mix__1_gain2].finalvalue);
  instanceschmitttrigger__1_i.dsp(net7, net29, PExch[PARAM_INDEX_schmitttrigger__1_hysteresis].finalvalue);
  instancevca__1_i.dsp(net34Latch, net29, net38);
  instancexfade__1_i.dsp(net7, net38, net31Latch, net36);
  instance_star___1_i.dsp(net23, net26Latch, net8);
  instanceNoiseGate__1_i.dsp(net0Latch, net4);
  instancehp__1_i.dsp(net4, 0 , 0 , net10, PExch[PARAM_INDEX_hp__1_pitch].finalvalue, PExch[PARAM_INDEX_hp__1_reso].finalvalue);
  instancemix__3_i.dsp(net10, zerobuffer, zerobuffer, net25, PExch[PARAM_INDEX_mix__3_gain1].finalvalue, PExch[PARAM_INDEX_mix__3_gain2].finalvalue);
  instanceout__1_i.dsp(net2, net3Latch, displayVector[3], displayVector[4]);
  instancexfade__2_i.dsp(net8, net37Latch, net31Latch, net35);
  instanceschmitttrigger__2_i.dsp(net8, net30, PExch[PARAM_INDEX_schmitttrigger__2_hysteresis].finalvalue);
  instancevca__2_i.dsp(net34Latch, net30, net37);
  instancemix__2_i.dsp(zerobuffer, net6Latch, net35, net3, PExch[PARAM_INDEX_mix__2_gain1].finalvalue, PExch[PARAM_INDEX_mix__2_gain2].finalvalue);
  instancein__1_i.dsp(net0, net1, displayVector[5], displayVector[6]);
  instancec__1_i.dsp(net33);
  instancehp__2_i.dsp(net5Latch, 0 , 0 , net11, PExch[PARAM_INDEX_hp__2_pitch].finalvalue, PExch[PARAM_INDEX_hp__2_reso].finalvalue);
  instancemix__4_i.dsp(net11, zerobuffer, zerobuffer, net26, PExch[PARAM_INDEX_mix__4_gain1].finalvalue, PExch[PARAM_INDEX_mix__4_gain2].finalvalue);
  instance_dash___1_i.dsp((net33<<21), net32Latch, net34);
  instancediv__1_i.dsp(net31Latch, net32);
  instancedial__2_i.dsp(net31, PExch[PARAM_INDEX_dial__2_value].finalvalue);
  instanceNoiseGate__2_i.dsp(net1, net5);
  instance_star___3_i.dsp(net9Latch, net24Latch, net6);
  instanceSubOscillator__1_i.dsp(net20, net21);
  instance_plus___1_i.dsp(net20, zerobuffer, net22);
  instance_star___4_i.dsp(net22, net28Latch, net24);
  instanceanalog__1_i.dsp(net12);
  instanceAD__to__int__1_i.dsp(net12, net13);
  instanceLFilter_space_Pitch_i.dsp((net13<<21));
  instancedial__1_i.dsp(net27, PExch[PARAM_INDEX_dial__1_value].finalvalue);
  instancead__1_i.dsp(net21, net9, PExch[PARAM_INDEX_ad__1_a].finalvalue, PExch[PARAM_INDEX_ad__1_d].finalvalue, PExch[PARAM_INDEX_ad__1_s].finalvalue, PExch[PARAM_INDEX_ad__1_r].finalvalue);
  instanceanalog__2_i.dsp(net14);
  instanceAD__to__int__2_i.dsp(net14, net15);
  instanceSubOsc_i.dsp((net15<<21));
  instancelp__1_i.dsp(net27, net28, PExch[PARAM_INDEX_lp__1_pitch].finalvalue, PExch[PARAM_INDEX_lp__1_reso].finalvalue);
  instancemidithru__1_i.dsp();
  instancemidithru__2_i.dsp();
  instanceanalog__3_i.dsp(net16);
  instanceAD__to__int__3_i.dsp(net16, net17);
  instanceSideCh_i.dsp((net17<<21));
  instanceanalog__4_i.dsp(net18);
  instanceAD__to__int__4_i.dsp(net18, net19);
  instanceDist_i.dsp((net19<<21));
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
   for(i=0;i<BUFSIZE;i++)
      net0Latch[i]=net0[i];
   for(i=0;i<BUFSIZE;i++)
      net3Latch[i]=net3[i];
   for(i=0;i<BUFSIZE;i++)
      net5Latch[i]=net5[i];
   for(i=0;i<BUFSIZE;i++)
      net6Latch[i]=net6[i];
net9Latch = net9;
   for(i=0;i<BUFSIZE;i++)
      net24Latch[i]=net24[i];
   for(i=0;i<BUFSIZE;i++)
      net25Latch[i]=net25[i];
   for(i=0;i<BUFSIZE;i++)
      net26Latch[i]=net26[i];
net28Latch = net28;
net31Latch = net31;
net32Latch = net32;
net34Latch = net34;
   for(i=0;i<BUFSIZE;i++)
      net36Latch[i]=net36[i];
   for(i=0;i<BUFSIZE;i++)
      net37Latch[i]=net37[i];
//--------- </net latch copy> ----------//
}

void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
instanceKickEnv__1_i.MidiInHandler(dev, port, status, data1, data2);
instanceNoiseGate__1_i.MidiInHandler(dev, port, status, data1, data2);
instancehp__1_i.MidiInHandler(dev, port, status, data1, data2);
instancehp__2_i.MidiInHandler(dev, port, status, data1, data2);
instancedial__2_i.MidiInHandler(dev, port, status, data1, data2);
instanceNoiseGate__2_i.MidiInHandler(dev, port, status, data1, data2);
instanceSubOscillator__1_i.MidiInHandler(dev, port, status, data1, data2);
instanceAD__to__int__1_i.MidiInHandler(dev, port, status, data1, data2);
instancedial__1_i.MidiInHandler(dev, port, status, data1, data2);
instanceAD__to__int__2_i.MidiInHandler(dev, port, status, data1, data2);
instancemidithru__1_i.MidiInHandler(dev, port, status, data1, data2);
instancemidithru__2_i.MidiInHandler(dev, port, status, data1, data2);
instanceAD__to__int__3_i.MidiInHandler(dev, port, status, data1, data2);
instanceAD__to__int__4_i.MidiInHandler(dev, port, status, data1, data2);
}

};

static rootc root;
void PatchProcess( int32_t * inbuf, int32_t * outbuf) {
  int i;
  for(i=0;i<BUFSIZE;i++){
    AudioInputLeft[i] = inbuf[i*2]>>4;
    switch(AudioInputMode) {
       case A_MONO:
             AudioInputRight[i] = AudioInputLeft[i];break;
       case A_BALANCED:
             AudioInputLeft[i] = (AudioInputLeft[i] - (inbuf[i*2+1]>>4) ) >> 1;
             AudioInputRight[i] = AudioInputLeft[i];             break;
       case A_STEREO:
       default:
             AudioInputRight[i] = inbuf[i*2+1]>>4;
     }
  }
  root.dsp();
  for(i=0;i<BUFSIZE;i++){
    outbuf[i*2] = __SSAT(AudioOutputLeft[i],28)<<4;
    switch(AudioOutputMode) {
       case A_MONO:
             outbuf[i*2+1] = 0;break;
       case A_BALANCED:
             outbuf[i*2+1] = ~ outbuf[i*2];break;
       case A_STEREO:
       default:
             outbuf[i*2+1] = __SSAT(AudioOutputRight[i],28)<<4;
     }
  }
}

void ApplyPreset(int32_t i) {
   root.ApplyPreset(i);
}

void PatchMidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2){
  root.MidiInHandler(dev, port, status, data1, data2);
}

typedef void (*funcp_t)(void);
typedef funcp_t * funcpp_t;
extern funcp_t __ctor_array_start;
extern funcp_t __ctor_array_end;extern funcp_t __dtor_array_start;
extern funcp_t __dtor_array_end;void PatchDispose( ) {
  root.Dispose();
  {
    funcpp_t fpp = &__dtor_array_start;
    while (fpp < &__dtor_array_end) {
      (*fpp)();
      fpp++;
    }
  }
}

void xpatch_init2(int fwid)
{
  if (fwid != 0xE95BAC96) {
    return;  }
  extern uint32_t _pbss_start;
  extern uint32_t _pbss_end;
  volatile uint32_t *p;
  for(p=&_pbss_start;p<&_pbss_end;p++) *p=0;
  {
    funcpp_t fpp = &__ctor_array_start;
    while (fpp < &__ctor_array_end) {
      (*fpp)();
      fpp++;
    }
  }
  patchMeta.npresets = 8;
  patchMeta.npreset_entries = 32;
  patchMeta.pPresets = (PresetParamChange_t*) root.GetPresets();
  patchMeta.pPExch = &root.PExch[0];
  patchMeta.pDisplayVector = &root.displayVector[0];
  patchMeta.numPEx = 35;
  patchMeta.patchID = -949650287;
  extern char _sdram_dyn_start;
  extern char _sdram_dyn_end;
  sdram_init(&_sdram_dyn_start,&_sdram_dyn_end);
  root.Init();
  patchMeta.fptr_applyPreset = ApplyPreset;
  patchMeta.fptr_patch_dispose = PatchDispose;
  patchMeta.fptr_MidiInHandler = PatchMidiInHandler;
  patchMeta.fptr_dsp_process = PatchProcess;
}
