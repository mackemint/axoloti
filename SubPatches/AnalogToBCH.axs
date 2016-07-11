<patch-1.0>
   <comment type="patch/comment" x="350" y="0" text="Selector"/>
   <comment type="patch/comment" x="126" y="14" text="Potentiometer input"/>
   <obj type="lfo/square" sha="b4420b58ca2ae5ece53d53540bc91bc9ed7a4b83" uuid="de6909eb64db13af5b43f979a4c130024b3a4793" name="square_1" x="350" y="14">
      <params>
         <frac32.s.map name="pitch" value="42.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="logic/counter" sha="519c79f42a7c84352830b08e68696ecbf5d0bd52" uuid="7a141ba82230e54e5f5cd12da5dbe5a74ba854a5" name="counter_1" x="448" y="14">
      <params>
         <int32 name="maximum" value="4"/>
      </params>
      <attribs/>
   </obj>
   <obj type="gpio/out/digital" sha="865e8be3f5cda67286c22728b3d3a38cf6c8002d" uuid="320eed040f6c55bb24c56416596ac2e67d0c82bc" name="digital_5" x="868" y="14">
      <params/>
      <attribs>
         <combo attributeName="pad" selection="PB0"/>
         <combo attributeName="mode" selection="Push pull"/>
      </attribs>
   </obj>
   <comment type="patch/comment" x="952" y="14" text="Cathode on LED"/>
   <obj type="gpio/in/analog" sha="e3ff2158ab5c372cfc7d9dddc5d64d55cd90c257" uuid="1c0c845ed2d7e06ae5f377ba13d9d09f4747ac87" name="analog_1" x="14" y="28">
      <params/>
      <attribs>
         <combo attributeName="channel" selection="PA0 (ADC1_IN0)"/>
      </attribs>
   </obj>
   <obj type="logic/decode/bin 8" sha="14c4de669a7c18d36691535d2acf6e439a232033" uuid="dfc0a6e9d7e817cec64fd01f6972f64d897863a4" name="int_1" x="210" y="28">
      <params/>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="1232" y="42" text="Anode on LED"/>
   <comment type="patch/comment" x="602" y="70" text="MSB"/>
   <obj type="ctrl/toggle" sha="f5742cc9eee76fae90a4e570c34596dd327b6c28" uuid="42b8134fa729d54bfc8d62d6ef3fa99498c1de99" name="toggle_1" x="700" y="70">
      <params>
         <bool32.tgl name="b" value="1"/>
      </params>
      <attribs/>
   </obj>
   <obj type="demux/demux 4" sha="c9c15bc93db182687d1bcc280e7e6e44828b2c01" uuid="2d85d32578993f1b062c98cb91f49ff3f0f4be47" name="demux_3" x="770" y="70">
      <params/>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="1358" y="70" text="LSB"/>
   <obj type="ctrl/dial p" sha="501c30e07dedf3d701e8d0b33c3c234908c3388e" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="dial_1" x="70" y="84">
      <params>
         <frac32.u.map name="value" value="61.5"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/div 4" sha="96a7c0765a638d8fc2cda60dcb59896abb613995" uuid="507955275561b256e540f7205386d31545a2828f" name="div_1" x="140" y="84">
      <params/>
      <attribs/>
   </obj>
   <obj type="mux/mux 4" sha="2a9cda02cb3c92c65b6ca93f59d55ce2101d6351" uuid="97b0e22b70b6c03c866599d0ac3ed3e9e6e5d4fc" name="mux_4" x="602" y="84">
      <params/>
      <attribs/>
   </obj>
   <obj type="gpio/out/digital" sha="865e8be3f5cda67286c22728b3d3a38cf6c8002d" uuid="320eed040f6c55bb24c56416596ac2e67d0c82bc" name="digital_6" x="868" y="84">
      <params/>
      <attribs>
         <combo attributeName="pad" selection="PB1"/>
         <combo attributeName="mode" selection="Push pull"/>
      </attribs>
   </obj>
   <obj type="gpio/out/digital" sha="865e8be3f5cda67286c22728b3d3a38cf6c8002d" uuid="320eed040f6c55bb24c56416596ac2e67d0c82bc" name="digital_1" x="1358" y="84">
      <params/>
      <attribs>
         <combo attributeName="pad" selection="PC3"/>
         <combo attributeName="mode" selection="Push pull"/>
      </attribs>
   </obj>
   <obj type="gpio/out/digital" sha="865e8be3f5cda67286c22728b3d3a38cf6c8002d" uuid="320eed040f6c55bb24c56416596ac2e67d0c82bc" name="digital_2" x="1274" y="98">
      <params/>
      <attribs>
         <combo attributeName="pad" selection="PC2"/>
         <combo attributeName="mode" selection="Push pull"/>
      </attribs>
   </obj>
   <comment type="patch/comment" x="1106" y="112" text="MSB"/>
   <obj type="gpio/out/digital" sha="865e8be3f5cda67286c22728b3d3a38cf6c8002d" uuid="320eed040f6c55bb24c56416596ac2e67d0c82bc" name="digital_3" x="1190" y="112">
      <params/>
      <attribs>
         <combo attributeName="pad" selection="PC1"/>
         <combo attributeName="mode" selection="Push pull"/>
      </attribs>
   </obj>
   <obj type="gpio/out/digital" sha="865e8be3f5cda67286c22728b3d3a38cf6c8002d" uuid="320eed040f6c55bb24c56416596ac2e67d0c82bc" name="digital_4" x="1106" y="126">
      <params/>
      <attribs>
         <combo attributeName="pad" selection="PC0"/>
         <combo attributeName="mode" selection="Push pull"/>
      </attribs>
   </obj>
   <obj type="gpio/out/digital" sha="865e8be3f5cda67286c22728b3d3a38cf6c8002d" uuid="320eed040f6c55bb24c56416596ac2e67d0c82bc" name="digital_7" x="868" y="154">
      <params/>
      <attribs>
         <combo attributeName="pad" selection="PB6"/>
         <combo attributeName="mode" selection="Push pull"/>
      </attribs>
   </obj>
   <obj type="gpio/in/analog" sha="e3ff2158ab5c372cfc7d9dddc5d64d55cd90c257" uuid="1c0c845ed2d7e06ae5f377ba13d9d09f4747ac87" name="analog_2" x="14" y="182">
      <params/>
      <attribs>
         <combo attributeName="channel" selection="PA1 (ADC1_IN1)"/>
      </attribs>
   </obj>
   <obj type="logic/decode/bin 8" sha="14c4de669a7c18d36691535d2acf6e439a232033" uuid="dfc0a6e9d7e817cec64fd01f6972f64d897863a4" name="int_2" x="210" y="182">
      <params/>
      <attribs/>
   </obj>
   <obj type="mux/mux 4" sha="2a9cda02cb3c92c65b6ca93f59d55ce2101d6351" uuid="97b0e22b70b6c03c866599d0ac3ed3e9e6e5d4fc" name="mux_3" x="602" y="182">
      <params/>
      <attribs/>
   </obj>
   <obj type="gpio/out/digital" sha="865e8be3f5cda67286c22728b3d3a38cf6c8002d" uuid="320eed040f6c55bb24c56416596ac2e67d0c82bc" name="digital_8" x="868" y="224">
      <params/>
      <attribs>
         <combo attributeName="pad" selection="PB7"/>
         <combo attributeName="mode" selection="Push pull"/>
      </attribs>
   </obj>
   <obj type="ctrl/dial p" sha="501c30e07dedf3d701e8d0b33c3c234908c3388e" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="dial_2" x="84" y="238">
      <params>
         <frac32.u.map name="value" value="28.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/div 4" sha="96a7c0765a638d8fc2cda60dcb59896abb613995" uuid="507955275561b256e540f7205386d31545a2828f" name="div_2" x="140" y="238">
      <params/>
      <attribs/>
   </obj>
   <obj type="mux/mux 4" sha="2a9cda02cb3c92c65b6ca93f59d55ce2101d6351" uuid="97b0e22b70b6c03c866599d0ac3ed3e9e6e5d4fc" name="mux_2" x="602" y="280">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/&lt;" sha="65a19110375857a3f7428a0abee85d491f8ef346" uuid="e1b31418165304d34c713638837722589dcacb6" name="&lt;_1" x="1414" y="280">
      <params/>
      <attribs/>
   </obj>
   <obj type="const/i" sha="15b9dce9232a04e8881936a6ea800e66ae8e0da9" uuid="e202f44b2df17ae0b3e663b98ea6b14c8ff00408" name="i_1" x="1288" y="308">
      <params/>
      <attribs>
         <spinner attributeName="value" value="8"/>
      </attribs>
   </obj>
   <obj type="gpio/in/analog" sha="e3ff2158ab5c372cfc7d9dddc5d64d55cd90c257" uuid="1c0c845ed2d7e06ae5f377ba13d9d09f4747ac87" name="analog_3" x="14" y="336">
      <params/>
      <attribs>
         <combo attributeName="channel" selection="PA2 (ADC1_IN2)"/>
      </attribs>
   </obj>
   <obj type="logic/decode/bin 8" sha="14c4de669a7c18d36691535d2acf6e439a232033" uuid="dfc0a6e9d7e817cec64fd01f6972f64d897863a4" name="int_3" x="210" y="336">
      <params/>
      <attribs/>
   </obj>
   <obj type="disp/bool" sha="330cd7d2342f59124b04a39d118a0ab97185ecaa" uuid="a0ee71d48208b71752cbb8c05e55145106ef3946" name="bool_4" x="1134" y="336">
      <params/>
      <attribs/>
   </obj>
   <obj type="disp/bool" sha="330cd7d2342f59124b04a39d118a0ab97185ecaa" uuid="a0ee71d48208b71752cbb8c05e55145106ef3946" name="bool_3" x="1148" y="336">
      <params/>
      <attribs/>
   </obj>
   <obj type="disp/bool" sha="330cd7d2342f59124b04a39d118a0ab97185ecaa" uuid="a0ee71d48208b71752cbb8c05e55145106ef3946" name="bool_2" x="1162" y="336">
      <params/>
      <attribs/>
   </obj>
   <obj type="disp/bool" sha="330cd7d2342f59124b04a39d118a0ab97185ecaa" uuid="a0ee71d48208b71752cbb8c05e55145106ef3946" name="bool_1" x="1176" y="336">
      <params/>
      <attribs/>
   </obj>
   <obj type="mux/mux 4" sha="2a9cda02cb3c92c65b6ca93f59d55ce2101d6351" uuid="97b0e22b70b6c03c866599d0ac3ed3e9e6e5d4fc" name="mux_1" x="602" y="378">
      <params/>
      <attribs/>
   </obj>
   <obj type="ctrl/dial p" sha="501c30e07dedf3d701e8d0b33c3c234908c3388e" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="dial_3" x="84" y="392">
      <params>
         <frac32.u.map name="value" value="13.5"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/div 4" sha="96a7c0765a638d8fc2cda60dcb59896abb613995" uuid="507955275561b256e540f7205386d31545a2828f" name="div_3" x="140" y="392">
      <params/>
      <attribs/>
   </obj>
   <obj type="demux/demux 2" sha="c50b27790ecf5ebd86af6c4ede6a6b2c9d6ea154" uuid="28788637ca4264670042a31303a9d6e100646ff0" name="demux_1" x="1442" y="392">
      <params/>
      <attribs/>
   </obj>
   <obj type="mux/mux 8" sha="f7d4be62cb834bc2e69ce78442f16b160f82fa3" uuid="39db4571d158ce2c2bc895f16048aee73f12d315" name="mux_5" x="1148" y="420">
      <params/>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="602" y="476" text="LSB"/>
   <obj type="gpio/in/analog" sha="e3ff2158ab5c372cfc7d9dddc5d64d55cd90c257" uuid="1c0c845ed2d7e06ae5f377ba13d9d09f4747ac87" name="analog_4" x="14" y="490">
      <params/>
      <attribs>
         <combo attributeName="channel" selection="PA3 (ADC1_IN3)"/>
      </attribs>
   </obj>
   <obj type="logic/decode/bin 8" sha="14c4de669a7c18d36691535d2acf6e439a232033" uuid="dfc0a6e9d7e817cec64fd01f6972f64d897863a4" name="int_4" x="210" y="490">
      <params/>
      <attribs/>
   </obj>
   <obj type="demux/demux 2" sha="c50b27790ecf5ebd86af6c4ede6a6b2c9d6ea154" uuid="28788637ca4264670042a31303a9d6e100646ff0" name="demux_2" x="1400" y="504">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/+" sha="748d226b7665f8addb97972e563e34b3fa57b22c" uuid="b94a9b8e9adcb7d18868c0ee808a9b211b65578d" name="+_1" x="1568" y="504">
      <params/>
      <attribs/>
   </obj>
   <obj type="math/&gt;" sha="6ce6ff4d125547d10653d4bac2820364d8297d6f" uuid="a459588d6498caeb4daf3a07f9d5e9b4a657262f" name="&gt;_1" x="1288" y="532">
      <params/>
      <attribs/>
   </obj>
   <obj type="ctrl/dial p" sha="501c30e07dedf3d701e8d0b33c3c234908c3388e" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="dial_4" x="84" y="546">
      <params>
         <frac32.u.map name="value" value="5.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/div 4" sha="96a7c0765a638d8fc2cda60dcb59896abb613995" uuid="507955275561b256e540f7205386d31545a2828f" name="div_4" x="140" y="546">
      <params/>
      <attribs/>
   </obj>
   <obj type="mux/mux 8" sha="f7d4be62cb834bc2e69ce78442f16b160f82fa3" uuid="39db4571d158ce2c2bc895f16048aee73f12d315" name="mux_6" x="1148" y="574">
      <params/>
      <attribs/>
   </obj>
   <comment type="patch/comment" x="70" y="756" text="Every pot has a 4 bit resolution. The selector scrolls through what pot value is going to be displayed"/>
   <obj type="logic/counter" sha="519c79f42a7c84352830b08e68696ecbf5d0bd52" uuid="7a141ba82230e54e5f5cd12da5dbe5a74ba854a5" name="counter_2" x="1050" y="840">
      <params>
         <int32 name="maximum" value="16"/>
      </params>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="dial_1" outlet="out"/>
         <dest obj="div_1" inlet="in"/>
      </net>
      <net>
         <source obj="dial_2" outlet="out"/>
         <dest obj="div_2" inlet="in"/>
      </net>
      <net>
         <source obj="dial_3" outlet="out"/>
         <dest obj="div_3" inlet="in"/>
      </net>
      <net>
         <source obj="dial_4" outlet="out"/>
         <dest obj="div_4" inlet="in"/>
      </net>
      <net>
         <source obj="square_1" outlet="wave"/>
         <dest obj="counter_1" inlet="trig"/>
      </net>
      <net>
         <source obj="counter_1" outlet="o"/>
         <dest obj="mux_1" inlet="s"/>
         <dest obj="mux_2" inlet="s"/>
         <dest obj="mux_3" inlet="s"/>
         <dest obj="mux_4" inlet="s"/>
         <dest obj="demux_3" inlet="s"/>
      </net>
      <net>
         <source obj="div_1" outlet="out"/>
         <dest obj="int_1" inlet="i1"/>
      </net>
      <net>
         <source obj="mux_1" outlet="o"/>
         <dest obj="bool_1" inlet="in"/>
         <dest obj="digital_1" inlet="in"/>
      </net>
      <net>
         <source obj="mux_2" outlet="o"/>
         <dest obj="bool_2" inlet="in"/>
         <dest obj="digital_2" inlet="in"/>
      </net>
      <net>
         <source obj="div_2" outlet="out"/>
         <dest obj="int_2" inlet="i1"/>
      </net>
      <net>
         <source obj="mux_3" outlet="o"/>
         <dest obj="bool_3" inlet="in"/>
         <dest obj="digital_3" inlet="in"/>
      </net>
      <net>
         <source obj="div_3" outlet="out"/>
         <dest obj="int_3" inlet="i1"/>
      </net>
      <net>
         <source obj="mux_4" outlet="o"/>
         <dest obj="digital_4" inlet="in"/>
         <dest obj="bool_4" inlet="in"/>
      </net>
      <net>
         <source obj="div_4" outlet="out"/>
         <dest obj="int_4" inlet="i1"/>
      </net>
      <net>
         <source obj="mux_5" outlet="o"/>
         <dest obj="demux_1" inlet="i"/>
      </net>
      <net>
         <source obj="demux_1" outlet="o0"/>
         <dest obj="+_1" inlet="in1"/>
      </net>
      <net>
         <source obj="&lt;_1" outlet="out"/>
         <dest obj="demux_1" inlet="s"/>
      </net>
      <net>
         <source obj="i_1" outlet="out"/>
         <dest obj="&lt;_1" inlet="in2"/>
         <dest obj="&gt;_1" inlet="in2"/>
      </net>
      <net>
         <source obj="counter_2" outlet="o"/>
         <dest obj="mux_5" inlet="s"/>
         <dest obj="mux_6" inlet="s"/>
         <dest obj="&lt;_1" inlet="in1"/>
         <dest obj="&gt;_1" inlet="in1"/>
      </net>
      <net>
         <source obj="demux_2" outlet="o1"/>
         <dest obj="+_1" inlet="in2"/>
      </net>
      <net>
         <source obj="mux_6" outlet="o"/>
         <dest obj="demux_2" inlet="i"/>
      </net>
      <net>
         <source obj="&gt;_1" outlet="out"/>
         <dest obj="demux_2" inlet="s"/>
      </net>
      <net>
         <source obj="int_1" outlet="o0"/>
         <dest obj="mux_1" inlet="i0"/>
         <dest obj="mux_5" inlet="i0"/>
      </net>
      <net>
         <source obj="int_1" outlet="o1"/>
         <dest obj="mux_2" inlet="i0"/>
         <dest obj="mux_5" inlet="i1"/>
      </net>
      <net>
         <source obj="int_1" outlet="o2"/>
         <dest obj="mux_3" inlet="i0"/>
         <dest obj="mux_5" inlet="i2"/>
      </net>
      <net>
         <source obj="int_1" outlet="o3"/>
         <dest obj="mux_4" inlet="i0"/>
         <dest obj="mux_5" inlet="i3"/>
      </net>
      <net>
         <source obj="int_2" outlet="o0"/>
         <dest obj="mux_1" inlet="i1"/>
         <dest obj="mux_5" inlet="i4"/>
      </net>
      <net>
         <source obj="int_2" outlet="o1"/>
         <dest obj="mux_2" inlet="i1"/>
         <dest obj="mux_5" inlet="i5"/>
      </net>
      <net>
         <source obj="int_2" outlet="o2"/>
         <dest obj="mux_3" inlet="i1"/>
         <dest obj="mux_5" inlet="i6"/>
      </net>
      <net>
         <source obj="int_2" outlet="o3"/>
         <dest obj="mux_4" inlet="i1"/>
         <dest obj="mux_5" inlet="i7"/>
      </net>
      <net>
         <source obj="int_3" outlet="o0"/>
         <dest obj="mux_1" inlet="i2"/>
         <dest obj="mux_6" inlet="i0"/>
      </net>
      <net>
         <source obj="int_3" outlet="o1"/>
         <dest obj="mux_2" inlet="i2"/>
         <dest obj="mux_6" inlet="i1"/>
      </net>
      <net>
         <source obj="int_3" outlet="o2"/>
         <dest obj="mux_3" inlet="i2"/>
         <dest obj="mux_6" inlet="i2"/>
      </net>
      <net>
         <source obj="int_3" outlet="o3"/>
         <dest obj="mux_4" inlet="i2"/>
         <dest obj="mux_6" inlet="i3"/>
      </net>
      <net>
         <source obj="int_4" outlet="o0"/>
         <dest obj="mux_1" inlet="i3"/>
         <dest obj="mux_6" inlet="i4"/>
      </net>
      <net>
         <source obj="int_4" outlet="o1"/>
         <dest obj="mux_2" inlet="i3"/>
         <dest obj="mux_6" inlet="i5"/>
      </net>
      <net>
         <source obj="int_4" outlet="o2"/>
         <dest obj="mux_3" inlet="i3"/>
         <dest obj="mux_6" inlet="i6"/>
      </net>
      <net>
         <source obj="int_4" outlet="o3"/>
         <dest obj="mux_4" inlet="i3"/>
         <dest obj="mux_6" inlet="i7"/>
      </net>
      <net>
         <source obj="toggle_1" outlet="o"/>
         <dest obj="demux_3" inlet="i"/>
      </net>
      <net>
         <source obj="demux_3" outlet="o0"/>
         <dest obj="digital_5" inlet="in"/>
      </net>
      <net>
         <source obj="demux_3" outlet="o1"/>
         <dest obj="digital_6" inlet="in"/>
      </net>
      <net>
         <source obj="demux_3" outlet="o2"/>
         <dest obj="digital_7" inlet="in"/>
      </net>
      <net>
         <source obj="demux_3" outlet="o3"/>
         <dest obj="digital_8" inlet="in"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>162</x>
      <y>22</y>
      <width>1758</width>
      <height>1054</height>
   </windowPos>
</patch-1.0>