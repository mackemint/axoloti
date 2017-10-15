<patch-1.0 appVersion="1.0.12">
   <comment type="patch/comment" x="420" y="14" text="Outputs Sample Hold themselves to keep the previous value on the output"/>
   <obj type="logic/samplehold" uuid="55479a62c4ed7e3536b6e6f339ce05a802a81b9d" name="samplehold_2" x="420" y="42">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet i" uuid="aae2176b26209e34e4fdeba5edb1ace82d178655" name="SHOutlet1" x="658" y="42">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet i" uuid="aae2176b26209e34e4fdeba5edb1ace82d178655" name="SHOutlet2" x="658" y="84">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet i" uuid="f11927f00c59219df0c50f73056aa19f125540b7" name="ADIn" x="42" y="126">
      <params/>
      <attribs/>
   </obj>
   <obj type="demux/demux 2" uuid="49737f48bfddf5d3ad9f98e4752b5b8bd5f566ad" name="demux_1" x="420" y="140">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet b" uuid="3b0d3eacb5bb978cb05d1372aa2714d5a4790844" name="ToggleIn" x="28" y="182">
      <params/>
      <attribs/>
   </obj>
   <obj type="logic/samplehold" uuid="55479a62c4ed7e3536b6e6f339ce05a802a81b9d" name="samplehold_1" x="420" y="266">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="ADIn" outlet="inlet"/>
         <dest obj="demux_1" inlet="i"/>
      </net>
      <net>
         <source obj="ToggleIn" outlet="inlet"/>
         <dest obj="samplehold_1" inlet="s_h"/>
         <dest obj="demux_1" inlet="s"/>
         <dest obj="samplehold_2" inlet="s_h"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o0"/>
         <dest obj="SHOutlet1" inlet="outlet"/>
         <dest obj="samplehold_1" inlet="in"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o1"/>
         <dest obj="SHOutlet2" inlet="outlet"/>
         <dest obj="samplehold_2" inlet="in"/>
      </net>
      <net>
         <source obj="samplehold_1" outlet="out"/>
         <dest obj="demux_1" inlet="d0"/>
      </net>
      <net>
         <source obj="samplehold_2" outlet="out"/>
         <dest obj="demux_1" inlet="d1"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>0</x>
      <y>23</y>
      <width>898</width>
      <height>685</height>
   </windowPos>
</patch-1.0>