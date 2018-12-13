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
   <obj type="const/i" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_1" x="616" y="196">
      <params/>
      <attribs>
         <spinner attributeName="value" value="24"/>
      </attribs>
   </obj>
   <obj type="math/*" uuid="3ac307b9f782049739ed62504081b96d580ea336" name="*_1" x="728" y="196">
      <params/>
      <attribs/>
   </obj>
   <obj type="gain/vca" uuid="a9f2dcd18043e2f47364e45cb8814f63c2a37c0d" name="vca_1" x="812" y="196">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="SubOscOut" x="896" y="196">
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
         <dest obj="*_1" inlet="b"/>
      </net>
      <net>
         <source obj="keyb_2" outlet="gate"/>
         <dest obj="GateOut" inlet="outlet"/>
      </net>
      <net>
         <source obj="keyb_2" outlet="note"/>
         <dest obj="sine_1" inlet="pitch"/>
      </net>
      <net>
         <source obj="keyb_2" outlet="velocity"/>
         <dest obj="vca_1" inlet="v"/>
      </net>
      <net>
         <source obj="*_1" outlet="result"/>
         <dest obj="vca_1" inlet="a"/>
      </net>
      <net>
         <source obj="i_1" outlet="out"/>
         <dest obj="*_1" inlet="a"/>
      </net>
      <net>
         <source obj="vca_1" outlet="o"/>
         <dest obj="SubOscOut" inlet="outlet"/>
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