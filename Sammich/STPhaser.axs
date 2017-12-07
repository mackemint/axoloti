<patch-1.0 appVersion="1.0.12">
   <obj type="patch/inlet a" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="InL" x="154" y="0">
      <params/>
      <attribs/>
   </obj>
   <obj type="sss/fx/phaserST" uuid="91696cab-4458-4b88-8c2a-fd9258ff280a" name="phaserST_1" x="378" y="14">
      <params>
         <frac32.s.map name="rate" value="12.0"/>
         <frac32.u.map name="depth" value="23.5"/>
         <frac32.u.map name="wet" MidiCC="5" value="0.0"/>
         <frac32.u.map name="dry" MidiCC="6" value="63.99999952316284"/>
         <int32 name="stages" value="4"/>
         <frac32.u.map name="spread" value="22.5"/>
         <frac32.s.map name="feed" value="44.0"/>
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
   <obj type="math/*c" uuid="7d5ef61c3bcd571ee6bbd8437ef3612125dfb225" name="*c_1" x="532" y="420">
      <params>
         <frac32.u.map name="amp" value="56.5"/>
      </params>
      <attribs/>
   </obj>
   <obj type="ctrl/dial p" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="DRY/WET" x="406" y="434">
      <params>
         <frac32.u.map name="value" onParent="true" MidiCC="3" value="0.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="midi/intern/cc thin" uuid="fd6026be5e7a856b804776c5d7d4df1a4480795e" name="WET" x="812" y="490">
      <params/>
      <attribs>
         <spinner attributeName="channel" value="7"/>
         <spinner attributeName="cc" value="5"/>
      </attribs>
   </obj>
   <obj type="const/i" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_1" x="630" y="560">
      <params/>
      <attribs>
         <spinner attributeName="value" value="64"/>
      </attribs>
   </obj>
   <obj type="math/-" uuid="3280bb759e9fc189e134300e48dda7e903c9a110" name="-_1" x="728" y="574">
      <params/>
      <attribs/>
   </obj>
   <obj type="midi/intern/cc thin" uuid="fd6026be5e7a856b804776c5d7d4df1a4480795e" name="DRY" x="812" y="574">
      <params/>
      <attribs>
         <spinner attributeName="channel" value="7"/>
         <spinner attributeName="cc" value="6"/>
      </attribs>
   </obj>
   <obj type="math/*c" uuid="7d5ef61c3bcd571ee6bbd8437ef3612125dfb225" name="*c_2" x="490" y="602">
      <params>
         <frac32.u.map name="amp" value="54.5"/>
      </params>
      <attribs/>
   </obj>
   <nets>
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
         <source obj="DRY/WET" outlet="out"/>
         <dest obj="*c_1" inlet="in"/>
         <dest obj="*c_2" inlet="in"/>
      </net>
      <net>
         <source obj="*c_1" outlet="out"/>
         <dest obj="WET" inlet="v"/>
      </net>
      <net>
         <source obj="*c_2" outlet="out"/>
         <dest obj="-_1" inlet="in2"/>
      </net>
      <net>
         <source obj="InL" outlet="inlet"/>
         <dest obj="phaserST_1" inlet="inL"/>
      </net>
      <net>
         <source obj="InR" outlet="inlet"/>
         <dest obj="phaserST_1" inlet="inR"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
      <MidiChannel>7</MidiChannel>
      <NPresets>2</NPresets>
      <NPresetEntries>32</NPresetEntries>
      <NModulationSources>2</NModulationSources>
      <NModulationTargetsPerSource>2</NModulationTargetsPerSource>
      <Author></Author>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>948</x>
      <y>392</y>
      <width>960</width>
      <height>668</height>
   </windowPos>
</patch-1.0>