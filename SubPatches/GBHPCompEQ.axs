<patch-1.0>
   <obj type="ctrl/toggle" sha="f5742cc9eee76fae90a4e570c34596dd327b6c28" uuid="42b8134fa729d54bfc8d62d6ef3fa99498c1de99" name="Bypass" x="1288" y="182">
      <params>
         <bool32.tgl name="b" onParent="true" value="0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="stomps/compressor1" uuid="be8148712e3b239dec6852f53bedc0965c794a47" name="CompL" x="1036" y="280">
      <params>
         <frac32.u.map name="comp_1:tresh" onParent="true" value="1.5"/>
         <frac32.u.map name="comp_1:ratio" onParent="true" value="23.5"/>
         <frac32.u.map name="smooth2_1:risetime" value="18.0"/>
         <frac32.u.map name="smooth2_1:falltime" value="17.5"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" sha="709c10aa648c6e5a3c00da4b5dd238899a7c109c" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="AudioInL" x="644" y="336">
      <params/>
      <attribs/>
   </obj>
   <obj type="filter/hp" sha="de47923046728f9eb4d6e6cbf26314bf518174fc" uuid="7829b56456e975f1d89bda2ad1c7ad678080a73b" name="HPL" x="798" y="336">
      <params>
         <frac32.s.map name="pitch" onParent="true" value="-36.0"/>
         <frac32.u.map name="reso" value="0.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="mux/mux 2" sha="10c5b6d774e8c972b6bb863dad23e83034e0990f" uuid="539c246f4c360ac476e128cfbfa84348fb7f7e73" name="demux_1" x="1386" y="336">
      <params/>
      <attribs/>
   </obj>
   <obj type="filter/eq4" sha="3f3b6079e9b4ea602f1fe88d3d565e698162bcff" uuid="e74037f1462a4ff4c609ebd11974780e4d486ba6" name="EQL" x="1260" y="364">
      <params>
         <int32 name="lowmid" onParent="true" value="-2"/>
         <int32 name="mid" onParent="true" value="-3"/>
         <int32 name="highmid" onParent="true" value="4"/>
         <int32 name="high" onParent="true" value="2"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" sha="9e7e04867e1d37837b0924c9bf18c44ac68602e6" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="OutL" x="1512" y="378">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" sha="709c10aa648c6e5a3c00da4b5dd238899a7c109c" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="AudioInR" x="630" y="588">
      <params/>
      <attribs/>
   </obj>
   <obj type="filter/hp" sha="de47923046728f9eb4d6e6cbf26314bf518174fc" uuid="7829b56456e975f1d89bda2ad1c7ad678080a73b" name="HPR" x="798" y="588">
      <params>
         <frac32.s.map name="pitch" onParent="true" value="-36.0"/>
         <frac32.u.map name="reso" value="0.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="stomps/compressor1" uuid="be8148712e3b239dec6852f53bedc0965c794a47" name="CompR" x="1036" y="588">
      <params>
         <frac32.u.map name="comp_1:tresh" onParent="true" value="1.5"/>
         <frac32.u.map name="comp_1:ratio" onParent="true" value="23.5"/>
         <frac32.u.map name="smooth2_1:risetime" value="18.0"/>
         <frac32.u.map name="smooth2_1:falltime" value="17.5"/>
      </params>
      <attribs/>
   </obj>
   <obj type="filter/eq4" sha="3f3b6079e9b4ea602f1fe88d3d565e698162bcff" uuid="e74037f1462a4ff4c609ebd11974780e4d486ba6" name="EQR" x="1246" y="588">
      <params>
         <int32 name="lowmid" onParent="true" value="-2"/>
         <int32 name="mid" onParent="true" value="-3"/>
         <int32 name="highmid" onParent="true" value="4"/>
         <int32 name="high" onParent="true" value="2"/>
      </params>
      <attribs/>
   </obj>
   <obj type="mux/mux 2" sha="10c5b6d774e8c972b6bb863dad23e83034e0990f" uuid="539c246f4c360ac476e128cfbfa84348fb7f7e73" name="demux_2" x="1400" y="602">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" sha="9e7e04867e1d37837b0924c9bf18c44ac68602e6" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="OutR" x="1512" y="602">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="HPL" outlet="out"/>
         <dest obj="CompL" inlet="in"/>
      </net>
      <net>
         <source obj="CompL" outlet="out"/>
         <dest obj="EQL" inlet="in"/>
      </net>
      <net>
         <source obj="HPR" outlet="out"/>
         <dest obj="CompR" inlet="in"/>
      </net>
      <net>
         <source obj="CompR" outlet="out"/>
         <dest obj="EQR" inlet="in"/>
      </net>
      <net>
         <source obj="EQR" outlet="out"/>
         <dest obj="demux_2" inlet="i2"/>
      </net>
      <net>
         <source obj="AudioInL" outlet="inlet"/>
         <dest obj="HPL" inlet="in"/>
         <dest obj="demux_1" inlet="i2"/>
      </net>
      <net>
         <source obj="AudioInR" outlet="inlet"/>
         <dest obj="HPR" inlet="in"/>
         <dest obj="demux_2" inlet="i1"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o"/>
         <dest obj="OutL" inlet="outlet"/>
      </net>
      <net>
         <source obj="EQL" outlet="out"/>
         <dest obj="demux_1" inlet="i1"/>
      </net>
      <net>
         <source obj="Bypass" outlet="o"/>
         <dest obj="demux_1" inlet="s"/>
         <dest obj="demux_2" inlet="s"/>
      </net>
      <net>
         <source obj="demux_2" outlet="o"/>
         <dest obj="OutR" inlet="outlet"/>
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