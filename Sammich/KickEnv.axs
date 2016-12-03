<patch-1.0 appVersion="1.0.10">
   <obj type="const/i" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_2" x="504" y="28">
      <params/>
      <attribs>
         <spinner attributeName="value" value="64"/>
      </attribs>
   </obj>
   <obj type="math/-" uuid="3280bb759e9fc189e134300e48dda7e903c9a110" name="-_1" x="630" y="42">
      <params/>
      <attribs/>
   </obj>
   <obj type="midi/in/keyb note ch" sha="20ea0a978c6a321329ddb1f8ed21a4110323f2c5" uuid="8cbbc80099dede5dc93d8d0d9b597c4188614de9" name="keyb_1" x="140" y="56">
      <params/>
      <attribs>
         <spinner attributeName="note" value="37"/>
         <spinner attributeName="channel" value="9"/>
      </attribs>
   </obj>
   <obj type="env/ahd lin" sha="de09ade5b46ad7c4bbe57ce1bb266f7b77fc2078" uuid="4ed5fd29254747e71db6d1d4caa20a89a41740f0" name="ahd_1" x="350" y="56">
      <params>
         <frac32.s.map name="a" value="-64.0"/>
         <frac32.s.map name="d" value="7.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="mix/xfade" uuid="bb87360199938d53d1183cdc80947ed0a39e3c9a" name="xfade_1" x="798" y="84">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet f" uuid="d18a9a550bcaaebac94e25983bd0e27dbfd7233c" name="outlet_1" x="1008" y="84">
      <params/>
      <attribs/>
   </obj>
   <obj type="const/i" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_1" x="630" y="112">
      <params/>
      <attribs>
         <spinner attributeName="value" value="64"/>
      </attribs>
   </obj>
   <comment type="patch/comment" x="140" y="168" text="Kick drum trigger ch#10"/>
   <obj type="ctrl/dial p" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="Threshold" x="630" y="182">
      <params>
         <frac32.u.map name="value" onParent="true" value="64.0"/>
      </params>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="keyb_1" outlet="gate"/>
         <dest obj="ahd_1" inlet="trig"/>
      </net>
      <net>
         <source obj="Threshold" outlet="out"/>
         <dest obj="xfade_1" inlet="c"/>
      </net>
      <net>
         <source obj="xfade_1" outlet="o"/>
         <dest obj="outlet_1" inlet="outlet"/>
      </net>
      <net>
         <source obj="ahd_1" outlet="env"/>
         <dest obj="-_1" inlet="in2"/>
      </net>
      <net>
         <source obj="i_1" outlet="out"/>
         <dest obj="xfade_1" inlet="i2"/>
      </net>
      <net>
         <source obj="i_2" outlet="out"/>
         <dest obj="-_1" inlet="in1"/>
      </net>
      <net>
         <source obj="-_1" outlet="out"/>
         <dest obj="xfade_1" inlet="i1"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>normal</subpatchmode>
      <MidiChannel>10</MidiChannel>
      <HasMidiChannelSelector>true</HasMidiChannelSelector>
      <NPresets>8</NPresets>
      <NPresetEntries>32</NPresetEntries>
      <NModulationSources>8</NModulationSources>
      <NModulationTargetsPerSource>8</NModulationTargetsPerSource>
      <Author>Markus Kaczmarek</Author>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>-3</x>
      <y>267</y>
      <width>1280</width>
      <height>773</height>
   </windowPos>
</patch-1.0>