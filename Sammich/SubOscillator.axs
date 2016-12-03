<patch-1.0 appVersion="1.0.10">
   <obj type="patch/outlet a" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="SubOscOut" x="504" y="112">
      <params/>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="322" y="182" text="Choose one octave down if &gt; 55"/>
   <comment type="patch/comment" x="504" y="182" text="SubOsc,Tuning"/>
   <obj type="mux/mux 2" sha="73ba55fbf61b80b78dd5cb4f0c4bd5cbbdd54ea0" uuid="3bcb8a666381ed18b8962eda50b1aa679136f618" name="+_1" x="420" y="196">
      <params/>
      <attribs/>
   </obj>
   <obj type="osc/sine" sha="edec4a9d5f533ea748cd564ce8c69673dd78742f" uuid="6e094045cca76a9dbf7ebfa72e44e4700d2b3ba" name="sine_1" x="490" y="196">
      <params>
         <frac32.s.map name="pitch" value="-11.899999618530273"/>
      </params>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="14" y="224" text="SubOsc,Ch#3"/>
   <obj type="midi/in/keyb zone" uuid="e7413176a91acc060036fd7f68fda24bbee265d3" name="keyb_2" x="14" y="238">
      <params/>
      <attribs>
         <spinner attributeName="startNote" value="0"/>
         <spinner attributeName="endNote" value="55"/>
      </attribs>
   </obj>
   <obj type="math/-" sha="50b9299d5a370749aa9d6cfdb949bf3191a1f68" uuid="3280bb759e9fc189e134300e48dda7e903c9a110" name="div_1" x="238" y="266">
      <params/>
      <attribs/>
   </obj>
   <obj type="const/i" sha="15b9dce9232a04e8881936a6ea800e66ae8e0da9" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_1" x="140" y="294">
      <params/>
      <attribs>
         <spinner attributeName="value" value="12"/>
      </attribs>
   </obj>
   <obj type="midi/in/keyb zone" uuid="e7413176a91acc060036fd7f68fda24bbee265d3" name="keyb_1" x="14" y="364">
      <params/>
      <attribs>
         <spinner attributeName="startNote" value="56"/>
         <spinner attributeName="endNote" value="127"/>
      </attribs>
   </obj>
   <obj type="patch/outlet b" uuid="191792f616d4835dba0b55375474a12942e5bcbd" name="GateOut" x="490" y="378">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/+" uuid="44553fdc8628c67ab535845ed1be304ad6c9553b" name="+_2" x="364" y="392">
      <params/>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="14" y="504" text="Same but transposed down one octave"/>
   <obj type="tb/midi/utils/midithru" uuid="b3868bd5-625c-4482-9948-a34e59fe2a21" name="midithru_1" x="140" y="532">
      <params/>
      <attribs>
         <combo attributeName="input" selection="din"/>
         <combo attributeName="output" selection="din"/>
         <combo attributeName="led" selection="on"/>
      </attribs>
   </obj>
   <nets>
      <net>
         <source obj="keyb_1" outlet="gate"/>
         <dest obj="+_1" inlet="s"/>
         <dest obj="+_2" inlet="in2"/>
      </net>
      <net>
         <source obj="keyb_1" outlet="note"/>
         <dest obj="div_1" inlet="in1"/>
      </net>
      <net>
         <source obj="i_1" outlet="out"/>
         <dest obj="div_1" inlet="in2"/>
      </net>
      <net>
         <source obj="div_1" outlet="out"/>
         <dest obj="+_1" inlet="i2"/>
      </net>
      <net>
         <source obj="+_1" outlet="o"/>
         <dest obj="sine_1" inlet="pitch"/>
      </net>
      <net>
         <source obj="keyb_2" outlet="note"/>
         <dest obj="+_1" inlet="i1"/>
      </net>
      <net>
         <source obj="sine_1" outlet="wave"/>
         <dest obj="SubOscOut" inlet="outlet"/>
      </net>
      <net>
         <source obj="+_2" outlet="out"/>
         <dest obj="GateOut" inlet="outlet"/>
      </net>
      <net>
         <source obj="keyb_2" outlet="gate"/>
         <dest obj="+_2" inlet="in1"/>
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
      <x>640</x>
      <y>23</y>
      <width>640</width>
      <height>773</height>
   </windowPos>
</patch-1.0>