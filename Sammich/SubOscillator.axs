<patch-1.0 appVersion="1.0.12">
   <comment type="patch/comment" x="364" y="182" text="SubOsc,Ch#3"/>
   <comment type="patch/comment" x="504" y="182" text="SubOsc,Tuning"/>
   <obj type="midi/in/keyb zone" uuid="e7413176a91acc060036fd7f68fda24bbee265d3" name="keyb_2" x="364" y="196">
      <params/>
      <attribs>
         <spinner attributeName="startNote" value="0"/>
         <spinner attributeName="endNote" value="127"/>
      </attribs>
   </obj>
   <obj type="osc/sine" uuid="6e094045cca76a9dbf7ebfa72e44e4700d2b3ba" name="sine_1" x="490" y="196">
      <params>
         <frac32.s.map name="pitch" value="-11.899999618530273"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="SubOscOut" x="602" y="196">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet b" uuid="191792f616d4835dba0b55375474a12942e5bcbd" name="GateOut" x="490" y="308">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="sine_1" outlet="wave"/>
         <dest obj="SubOscOut" inlet="outlet"/>
      </net>
      <net>
         <source obj="keyb_2" outlet="gate"/>
         <dest obj="GateOut" inlet="outlet"/>
      </net>
      <net>
         <source obj="keyb_2" outlet="note"/>
         <dest obj="sine_1" inlet="pitch"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>normal</subpatchmode>
      <MidiChannel>3</MidiChannel>
      <HasMidiChannelSelector>true</HasMidiChannelSelector>
      <NPresets>8</NPresets>
      <NPresetEntries>32</NPresetEntries>
      <NModulationSources>8</NModulationSources>
      <NModulationTargetsPerSource>8</NModulationTargetsPerSource>
      <Author>Markus Kaczmarek</Author>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>0</x>
      <y>23</y>
      <width>1040</width>
      <height>656</height>
   </windowPos>
</patch-1.0>