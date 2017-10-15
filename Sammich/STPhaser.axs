<patch-1.0 appVersion="1.0.12">
   <obj type="patch/inlet a" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="InL" x="154" y="0">
      <params/>
      <attribs/>
   </obj>
   <obj type="sss/fx/phaserST" uuid="91696cab-4458-4b88-8c2a-fd9258ff280a" name="phaserST_1" x="378" y="14">
      <params>
         <frac32.s.map name="rate" value="12.0"/>
         <frac32.u.map name="depth" MidiCC="1" value="0.0"/>
         <frac32.u.map name="wet" MidiCC="1" value="0.0"/>
         <frac32.u.map name="dry" MidiCC="2" value="63.99999952316284"/>
         <int32 name="stages" value="4"/>
         <frac32.u.map name="spread" value="22.5"/>
         <frac32.s.map name="feed" value="58.0"/>
      </params>
      <attribs>
         <combo attributeName="size" selection="1024 (21.33ms)"/>
      </attribs>
   </obj>
   <obj type="patch/outlet a" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="OutL" x="518" y="14">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="InR" x="154" y="42">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="OutR" x="518" y="56">
      <params/>
      <attribs/>
   </obj>
   <obj type="lfo/sine" uuid="75f7330c26a13953215dccc3b7b9008545c9daa9" name="sine_3" x="126" y="84">
      <params>
         <frac32.s.map name="pitch" value="-60.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="lfo/sine" uuid="75f7330c26a13953215dccc3b7b9008545c9daa9" name="sine_2" x="126" y="168">
      <params>
         <frac32.s.map name="pitch" value="-64.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="audio/out stereo" uuid="a1ca7a567f535acc21055669829101d3ee7f0189" name="out_1" x="630" y="238">
      <params/>
      <attribs/>
   </obj>
   <obj type="lfo/sine" uuid="75f7330c26a13953215dccc3b7b9008545c9daa9" name="sine_1" x="126" y="252">
      <params>
         <frac32.s.map name="pitch" value="-46.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/inlet i" uuid="f11927f00c59219df0c50f73056aa19f125540b7" name="MIDIIn" x="154" y="378">
      <params/>
      <attribs/>
   </obj>
   <obj type="audio/in stereo" uuid="99848ad6d90a8e615e83b2e619cfc806f28e7281" name="in_1" x="126" y="448">
      <params/>
      <attribs/>
   </obj>
   <obj type="midi/intern/cc thin" uuid="fd6026be5e7a856b804776c5d7d4df1a4480795e" name="WET" x="812" y="490">
      <params/>
      <attribs>
         <spinner attributeName="channel" value="2"/>
         <spinner attributeName="cc" value="1"/>
      </attribs>
   </obj>
   <obj type="const/i" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_1" x="630" y="560">
      <params/>
      <attribs>
         <spinner attributeName="value" value="64"/>
      </attribs>
   </obj>
   <obj type="math/-" uuid="1643d55e6e7ce1c995a5e66db9f54fd969e6c9b7" name="-_1" x="728" y="574">
      <params/>
      <attribs/>
   </obj>
   <obj type="midi/intern/cc thin" uuid="fd6026be5e7a856b804776c5d7d4df1a4480795e" name="DRY" x="812" y="574">
      <params/>
      <attribs>
         <spinner attributeName="channel" value="2"/>
         <spinner attributeName="cc" value="2"/>
      </attribs>
   </obj>
   <obj type="midi/intern/cc thin" uuid="fd6026be5e7a856b804776c5d7d4df1a4480795e" name="LFilter Pitch" x="504" y="742">
      <params/>
      <attribs>
         <spinner attributeName="channel" value="2"/>
         <spinner attributeName="cc" value="5"/>
      </attribs>
   </obj>
   <obj type="gpio/in/analog" uuid="1c0c845ed2d7e06ae5f377ba13d9d09f4747ac87" name="analog_1" x="56" y="770">
      <params/>
      <attribs>
         <combo attributeName="channel" selection="PC0 (ADC1_IN10)"/>
      </attribs>
   </obj>
   <obj type="./AD_to_int" uuid="34a84ffa-22f7-42fa-851f-6ff304fe4983" name="AD_to_int_1" x="210" y="798">
      <params/>
      <attribs/>
   </obj>
   <obj type="./SHDemux" uuid="5eb3c5ed-82d5-4164-808c-4175adb996d8" name="SHDemux_1" x="308" y="798">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="sine_1" outlet="wave"/>
         <dest obj="phaserST_1" inlet="spread"/>
      </net>
      <net>
         <source obj="sine_2" outlet="wave"/>
         <dest obj="phaserST_1" inlet="depth"/>
      </net>
      <net>
         <source obj="sine_3" outlet="wave"/>
         <dest obj="phaserST_1" inlet="rate"/>
      </net>
      <net>
         <source obj="phaserST_1" outlet="outL"/>
         <dest obj="OutL" inlet="outlet"/>
      </net>
      <net>
         <source obj="phaserST_1" outlet="outR"/>
         <dest obj="OutR" inlet="outlet"/>
      </net>
      <net>
         <source obj="-_1" outlet="out"/>
         <dest obj="DRY" inlet="v"/>
      </net>
      <net>
         <source obj="i_1" outlet="out"/>
         <dest obj="-_1" inlet="in1"/>
      </net>
      <net>
         <source obj="AD_to_int_1" outlet="Out"/>
         <dest obj="SHDemux_1" inlet="ADIn"/>
      </net>
      <net>
         <source obj="SHDemux_1" outlet="SHOutlet1"/>
         <dest obj="LFilter Pitch" inlet="v"/>
      </net>
      <net>
         <source obj="InL" outlet="inlet"/>
         <dest obj="phaserST_1" inlet="inL"/>
      </net>
      <net>
         <source obj="InR" outlet="inlet"/>
         <dest obj="phaserST_1" inlet="inR"/>
      </net>
      <net>
         <source obj="MIDIIn" outlet="inlet"/>
         <dest obj="WET" inlet="v"/>
         <dest obj="-_1" inlet="in2"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
      <MidiChannel>2</MidiChannel>
      <NPresets>8</NPresets>
      <NPresetEntries>32</NPresetEntries>
      <NModulationSources>8</NModulationSources>
      <NModulationTargetsPerSource>8</NModulationTargetsPerSource>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>0</x>
      <y>23</y>
      <width>960</width>
      <height>1052</height>
   </windowPos>
</patch-1.0>