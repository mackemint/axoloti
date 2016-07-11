<patch-1.0>
   <obj type="gain/vca" sha="c904cdd24d65968df2f5796e107db3747dd691a6" uuid="a9f2dcd18043e2f47364e45cb8814f63c2a37c0d" name="GainLeft" x="742" y="266">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/+" sha="9f8cb68e327acfaa43539be73ff97faab497ad45" uuid="faedbea4612d9bd3644d6d3bf31946d848a70e19" name="+_2" x="826" y="266">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" sha="9e7e04867e1d37837b0924c9bf18c44ac68602e6" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="OutL" x="910" y="280">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" sha="709c10aa648c6e5a3c00da4b5dd238899a7c109c" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="InL" x="462" y="308">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/+" sha="9f8cb68e327acfaa43539be73ff97faab497ad45" uuid="faedbea4612d9bd3644d6d3bf31946d848a70e19" name="+_1" x="602" y="308">
      <params/>
      <attribs/>
   </obj>
   <obj type="gain/vca" sha="c904cdd24d65968df2f5796e107db3747dd691a6" uuid="a9f2dcd18043e2f47364e45cb8814f63c2a37c0d" name="GainSummed" x="742" y="322">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" sha="709c10aa648c6e5a3c00da4b5dd238899a7c109c" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="InR" x="462" y="350">
      <params/>
      <attribs/>
   </obj>
   <obj type="gain/vca" sha="c904cdd24d65968df2f5796e107db3747dd691a6" uuid="a9f2dcd18043e2f47364e45cb8814f63c2a37c0d" name="GainRight" x="742" y="378">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/+" sha="9f8cb68e327acfaa43539be73ff97faab497ad45" uuid="faedbea4612d9bd3644d6d3bf31946d848a70e19" name="+_3" x="826" y="378">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" sha="9e7e04867e1d37837b0924c9bf18c44ac68602e6" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="OutR" x="910" y="378">
      <params/>
      <attribs/>
   </obj>
   <obj type="ctrl/dial p" sha="501c30e07dedf3d701e8d0b33c3c234908c3388e" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="Mono/Stereo" x="462" y="476">
      <params>
         <frac32.u.map name="value" onParent="true" value="64.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/div 64" sha="e63365a7cd04c05a073cdb3f5214f9c2e8d03214" uuid="da82c8ea54e956811f1d7264d921628e3301971e" name="0-1" x="532" y="476">
      <params/>
      <attribs/>
   </obj>
   <obj type="const/i" sha="15b9dce9232a04e8881936a6ea800e66ae8e0da9" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_1" x="532" y="518">
      <params/>
      <attribs>
         <spinner attributeName="value" value="1"/>
      </attribs>
   </obj>
   <obj type="math/-" sha="554de2692f3e366237f42785f5b0d75ff7823aa3" uuid="1643d55e6e7ce1c995a5e66db9f54fd969e6c9b7" name="-_1" x="616" y="518">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="InR" outlet="inlet"/>
         <dest obj="GainRight" inlet="a"/>
         <dest obj="+_1" inlet="in2"/>
      </net>
      <net>
         <source obj="InL" outlet="inlet"/>
         <dest obj="GainLeft" inlet="a"/>
         <dest obj="+_1" inlet="in1"/>
      </net>
      <net>
         <source obj="+_1" outlet="out"/>
         <dest obj="GainSummed" inlet="a"/>
      </net>
      <net>
         <source obj="Mono/Stereo" outlet="out"/>
         <dest obj="0-1" inlet="in"/>
      </net>
      <net>
         <source obj="0-1" outlet="out"/>
         <dest obj="GainRight" inlet="v"/>
         <dest obj="GainLeft" inlet="v"/>
         <dest obj="-_1" inlet="in2"/>
      </net>
      <net>
         <source obj="i_1" outlet="out"/>
         <dest obj="-_1" inlet="in1"/>
      </net>
      <net>
         <source obj="-_1" outlet="out"/>
         <dest obj="GainSummed" inlet="v"/>
      </net>
      <net>
         <source obj="GainSummed" outlet="o"/>
         <dest obj="+_2" inlet="in2"/>
         <dest obj="+_3" inlet="in1"/>
      </net>
      <net>
         <source obj="GainLeft" outlet="o"/>
         <dest obj="+_2" inlet="in1"/>
      </net>
      <net>
         <source obj="GainRight" outlet="o"/>
         <dest obj="+_3" inlet="in2"/>
      </net>
      <net>
         <source obj="+_2" outlet="out"/>
         <dest obj="OutL" inlet="outlet"/>
      </net>
      <net>
         <source obj="+_3" outlet="out"/>
         <dest obj="OutR" inlet="outlet"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>0</x>
      <y>22</y>
      <width>1920</width>
      <height>1054</height>
   </windowPos>
</patch-1.0>