<patch-1.0>
   <obj type="filter/eq4" sha="3f3b6079e9b4ea602f1fe88d3d565e698162bcff" uuid="e74037f1462a4ff4c609ebd11974780e4d486ba6" name="eq5hq_1" x="224" y="42">
      <params>
         <int32 name="lowmid" value="0"/>
         <int32 name="mid" value="-1"/>
         <int32 name="highmid" value="0"/>
         <int32 name="high" value="3"/>
      </params>
      <attribs/>
   </obj>
   <obj type="filter/bp svf" sha="ba4ac02f48ae93c7ecc9fac9b0e212cac7c21539" uuid="451629d3f559049e7f516d5014f3d5fa818827c7" name="bp_1" x="322" y="42">
      <params>
         <frac32.s.map name="pitch" value="-27.0"/>
         <frac32.u.map name="reso" value="5.5"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/+" sha="9f8cb68e327acfaa43539be73ff97faab497ad45" uuid="faedbea4612d9bd3644d6d3bf31946d848a70e19" name="+_2" x="448" y="42">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" sha="709c10aa648c6e5a3c00da4b5dd238899a7c109c" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="InL" x="42" y="56">
      <params/>
      <attribs/>
   </obj>
   <obj type="mux/mux 2" sha="10c5b6d774e8c972b6bb863dad23e83034e0990f" uuid="539c246f4c360ac476e128cfbfa84348fb7f7e73" name="demux_1" x="518" y="56">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" sha="9e7e04867e1d37837b0924c9bf18c44ac68602e6" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="OutL" x="616" y="70">
      <params/>
      <attribs/>
   </obj>
   <obj type="ctrl/toggle" sha="f5742cc9eee76fae90a4e570c34596dd327b6c28" uuid="42b8134fa729d54bfc8d62d6ef3fa99498c1de99" name="Bypass_" x="364" y="154">
      <params>
         <bool32.tgl name="b" onParent="true" value="0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="filter/eq4" sha="3f3b6079e9b4ea602f1fe88d3d565e698162bcff" uuid="e74037f1462a4ff4c609ebd11974780e4d486ba6" name="eq5hq_2" x="224" y="224">
      <params>
         <int32 name="lowmid" value="0"/>
         <int32 name="mid" value="-1"/>
         <int32 name="highmid" value="0"/>
         <int32 name="high" value="3"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/+" sha="9f8cb68e327acfaa43539be73ff97faab497ad45" uuid="faedbea4612d9bd3644d6d3bf31946d848a70e19" name="+_1" x="448" y="224">
      <params/>
      <attribs/>
   </obj>
   <obj type="mux/mux 2" sha="10c5b6d774e8c972b6bb863dad23e83034e0990f" uuid="539c246f4c360ac476e128cfbfa84348fb7f7e73" name="demux_2" x="518" y="238">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" sha="709c10aa648c6e5a3c00da4b5dd238899a7c109c" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="InR" x="42" y="252">
      <params/>
      <attribs/>
   </obj>
   <obj type="filter/bp svf" sha="ba4ac02f48ae93c7ecc9fac9b0e212cac7c21539" uuid="451629d3f559049e7f516d5014f3d5fa818827c7" name="bp_2" x="336" y="252">
      <params>
         <frac32.s.map name="pitch" value="-27.0"/>
         <frac32.u.map name="reso" value="5.5"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" sha="9e7e04867e1d37837b0924c9bf18c44ac68602e6" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="OutR" x="616" y="252">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="InR" outlet="inlet"/>
         <dest obj="demux_2" inlet="i2"/>
         <dest obj="eq5hq_2" inlet="in"/>
      </net>
      <net>
         <source obj="Bypass_" outlet="o"/>
         <dest obj="demux_2" inlet="s"/>
         <dest obj="demux_1" inlet="s"/>
      </net>
      <net>
         <source obj="eq5hq_1" outlet="out"/>
         <dest obj="bp_1" inlet="in"/>
         <dest obj="+_2" inlet="in1"/>
      </net>
      <net>
         <source obj="eq5hq_2" outlet="out"/>
         <dest obj="+_1" inlet="in1"/>
         <dest obj="bp_2" inlet="in"/>
      </net>
      <net>
         <source obj="+_1" outlet="out"/>
         <dest obj="demux_2" inlet="i1"/>
      </net>
      <net>
         <source obj="bp_2" outlet="out"/>
         <dest obj="+_1" inlet="in2"/>
      </net>
      <net>
         <source obj="+_2" outlet="out"/>
         <dest obj="demux_1" inlet="i1"/>
      </net>
      <net>
         <source obj="bp_1" outlet="out"/>
         <dest obj="+_2" inlet="in2"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o"/>
         <dest obj="OutL" inlet="outlet"/>
      </net>
      <net>
         <source obj="demux_2" outlet="o"/>
         <dest obj="OutR" inlet="outlet"/>
      </net>
      <net>
         <source obj="InL" outlet="inlet"/>
         <dest obj="eq5hq_1" inlet="in"/>
         <dest obj="demux_1" inlet="i2"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>0</x>
      <y>22</y>
      <width>960</width>
      <height>1054</height>
   </windowPos>
</patch-1.0>