<patch-1.0>
   <comment type="patch/comment" x="672" y="112" text="Count in"/>
   <obj type="patch/inlet i" sha="525f64aba3d51dde5253cccedd116ec84bf5d5d1" uuid="f11927f00c59219df0c50f73056aa19f125540b7" name="inlet_3" x="672" y="126">
      <params/>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="378" y="210" text="Change sequence only at the beginning of a beat"/>
   <comment type="patch/comment" x="84" y="238" text="MIDI note trig input"/>
   <obj type="patch/inlet b" sha="17c8e188371661163bfa55cea9974eecb785fb06" uuid="3b0d3eacb5bb978cb05d1372aa2714d5a4790844" name="inlet_1" x="84" y="252">
      <params/>
      <attribs/>
   </obj>
   <obj type="logic/flipflop toggle" sha="3e483f67f78cab4aecc6bc5cf4e105e481839660" uuid="195e489e5fc3d275944b0de56c7a91c8641ea22a" name="flipflop_1" x="518" y="252">
      <params/>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="84" y="308" text="Wrap at 0 input"/>
   <obj type="patch/inlet i" sha="525f64aba3d51dde5253cccedd116ec84bf5d5d1" uuid="f11927f00c59219df0c50f73056aa19f125540b7" name="inlet_2" x="84" y="322">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/==" sha="656917333ccb0d828ada5c46658123ca258a96b2" uuid="deaf0d36642c57876c4101e86f8a0b6a06021ab2" name="==_1" x="420" y="322">
      <params/>
      <attribs/>
   </obj>
   <obj type="logic/and 2" sha="fcf3c7b64624a2ee10ab0923e03af3f1e8e2a648" uuid="c67031682f552aa0a80b23377495c51ea28a8c9c" name="and_1" x="616" y="336">
      <params/>
      <attribs/>
   </obj>
   <obj type="demux/demux 4" sha="34b2b36c896755f98a1e6e03ac3b82f03b71af64" uuid="4da60a7524bf1ac90deef1b3a5e49919063b49cb" name="demux_1" x="868" y="364">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet i" sha="9c18b5ec0ea721bb98852ab326891478ca87a360" uuid="aae2176b26209e34e4fdeba5edb1ace82d178655" name="outlet_1" x="994" y="378">
      <params/>
      <attribs/>
   </obj>
   <obj type="const/i" sha="15b9dce9232a04e8881936a6ea800e66ae8e0da9" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_1" x="294" y="406">
      <params/>
      <attribs>
         <spinner attributeName="value" value="0"/>
      </attribs>
   </obj>
   <obj type="logic/counter" sha="77a4b4804913310c0ec3fcc53592eed1cd9af148" name="counter_2" x="686" y="434">
      <params>
         <int32 name="maximum" value="4"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/outlet i" sha="9c18b5ec0ea721bb98852ab326891478ca87a360" uuid="aae2176b26209e34e4fdeba5edb1ace82d178655" name="outlet_2" x="994" y="434">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet i" sha="9c18b5ec0ea721bb98852ab326891478ca87a360" uuid="aae2176b26209e34e4fdeba5edb1ace82d178655" name="outlet_3" x="994" y="490">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet i" sha="9c18b5ec0ea721bb98852ab326891478ca87a360" uuid="aae2176b26209e34e4fdeba5edb1ace82d178655" name="outlet_4" x="994" y="546">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="counter_2" outlet="o"/>
         <dest obj="demux_1" inlet="s"/>
      </net>
      <net>
         <source obj="flipflop_1" outlet="o"/>
         <dest obj="and_1" inlet="i1"/>
      </net>
      <net>
         <source obj="and_1" outlet="o"/>
         <dest obj="counter_2" inlet="trig"/>
         <dest obj="flipflop_1" inlet="reset"/>
      </net>
      <net>
         <source obj="==_1" outlet="out"/>
         <dest obj="and_1" inlet="i2"/>
      </net>
      <net>
         <source obj="i_1" outlet="out"/>
         <dest obj="==_1" inlet="in2"/>
      </net>
      <net>
         <source obj="inlet_1" outlet="inlet"/>
         <dest obj="flipflop_1" inlet="trig"/>
      </net>
      <net>
         <source obj="inlet_2" outlet="inlet"/>
         <dest obj="==_1" inlet="in1"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o0"/>
         <dest obj="outlet_1" inlet="outlet"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o1"/>
         <dest obj="outlet_2" inlet="outlet"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o2"/>
         <dest obj="outlet_3" inlet="outlet"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o3"/>
         <dest obj="outlet_4" inlet="outlet"/>
      </net>
      <net>
         <source obj="inlet_3" outlet="inlet"/>
         <dest obj="demux_1" inlet="i"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>1920</x>
      <y>0</y>
      <width>1280</width>
      <height>800</height>
   </windowPos>
</patch-1.0>