<patch-1.0>
   <obj type="filter/vcf3" sha="2a5cccf4517f54d2450ab7518925f49e4c41c837" uuid="92455c652cd098cbb682a5497baa18abbf2ef865" name="Filter" x="546" y="0">
      <params>
         <frac32.s.map name="pitch" onParent="true" value="-7.0"/>
         <frac32.u.map name="reso" onParent="true" value="20.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" sha="709c10aa648c6e5a3c00da4b5dd238899a7c109c" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="AudioIn" x="70" y="98">
      <params/>
      <attribs/>
   </obj>
   <obj type="env/follower" sha="8074c80ff135ec9b250e19c7a6671f8369b45ae4" name="follower_1" x="210" y="98">
      <params/>
      <attribs>
         <combo attributeName="time" selection="1.3ms"/>
      </attribs>
   </obj>
   <obj type="ctrl/dial p" sha="501c30e07dedf3d701e8d0b33c3c234908c3388e" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="ModAmt" x="392" y="98">
      <params>
         <frac32.u.map name="value" onParent="true" value="53.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" sha="9e7e04867e1d37837b0924c9bf18c44ac68602e6" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="AudioOut" x="812" y="98">
      <params/>
      <attribs/>
   </obj>
   <obj type="dyn/comp" sha="cda5bd26e9fc97319943991cca7cf2da17496790" uuid="2d62720d6a597c586936be74ebb1e1c449772636" name="comp_1" x="322" y="140">
      <params>
         <frac32.u.map name="tresh" onParent="true" value="2.5"/>
         <frac32.u.map name="ratio" value="64.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/*" sha="a380d86c2bc116d90e7b5eb49277941d4e9343d1" uuid="c16a625a661f40e4b359db604dcd00b3befcdbe3" name="double_1" x="168" y="196">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/&gt;" sha="99f01ed095dd5744b9271051ea6d4ea12ddaef84" uuid="8112942c245dbc2edf7d7de122fe83b0dcd0a391" name="&gt;_1" x="476" y="210">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet f" sha="c0c4ce40c7dec73dfbb009fd86c9b89c068b137a" uuid="d18a9a550bcaaebac94e25983bd0e27dbfd7233c" name="AudioOut_" x="756" y="210">
      <params/>
      <attribs/>
   </obj>
   <obj type="env/ahd lin m" sha="1bff4be3aeae590d80327085f5f7c771667d8938" uuid="f9b46834ce96425064b4ed7f53ad8b91ea1ac0ef" name="EnvAD" x="546" y="224">
      <params>
         <frac32.s.map name="a" onParent="true" value="-64.0"/>
         <frac32.s.map name="d" onParent="true" value="17.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="ctrl/dial p" sha="501c30e07dedf3d701e8d0b33c3c234908c3388e" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="dial_1" x="56" y="266">
      <params>
         <frac32.u.map name="value" onParent="true" value="0.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/smooth2" sha="7a49483fff392fd1c10fb15f40dfc8f92f942192" name="smooth2_1" x="392" y="266">
      <params>
         <frac32.u.map name="risetime" value="0.0"/>
         <frac32.u.map name="falltime" value="0.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="disp/chart b" sha="9af68e71368a6c4e7c4553b8bfd762831554a32e" uuid="d2bdf496f96ee521628490a038411210fbe29b15" name="chart_1" x="714" y="322">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="follower_1" outlet="amp"/>
         <dest obj="comp_1" inlet="in"/>
      </net>
      <net>
         <source obj="AudioIn" outlet="inlet"/>
         <dest obj="Filter" inlet="in"/>
         <dest obj="double_1" inlet="a"/>
      </net>
      <net>
         <source obj="comp_1" outlet="out"/>
         <dest obj="smooth2_1" inlet="in"/>
      </net>
      <net>
         <source obj="EnvAD" outlet="env"/>
         <dest obj="chart_1" inlet="in"/>
         <dest obj="Filter" inlet="pitch"/>
         <dest obj="AudioOut_" inlet="outlet"/>
      </net>
      <net>
         <source obj="ModAmt" outlet="out"/>
         <dest obj="&gt;_1" inlet="in2"/>
      </net>
      <net>
         <source obj="&gt;_1" outlet="out"/>
         <dest obj="EnvAD" inlet="trig"/>
      </net>
      <net>
         <source obj="smooth2_1" outlet="out"/>
         <dest obj="&gt;_1" inlet="in1"/>
      </net>
      <net>
         <source obj="Filter" outlet="out"/>
         <dest obj="AudioOut" inlet="outlet"/>
      </net>
      <net>
         <source obj="double_1" outlet="result"/>
         <dest obj="follower_1" inlet="in"/>
      </net>
      <net>
         <source obj="dial_1" outlet="out"/>
         <dest obj="double_1" inlet="b"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>160</x>
      <y>52</y>
      <width>939</width>
      <height>696</height>
   </windowPos>
</patch-1.0>