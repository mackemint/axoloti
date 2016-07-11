<patch-1.0>
   <obj type="patch/inlet i" sha="525f64aba3d51dde5253cccedd116ec84bf5d5d1" uuid="f11927f00c59219df0c50f73056aa19f125540b7" name="IntIn" x="56" y="196">
      <params/>
      <attribs/>
   </obj>
   <obj type="demux/demux 2" sha="20a44035a1a0fc8c8209f12b7507ef1aeec4789f" uuid="357def86905d97a677c7080b4c9a2a4c0b8cd0fe" name="demux_3" x="168" y="210">
      <params/>
      <attribs/>
   </obj>
   <obj type="logic/samplehold" sha="689ed4c57ac833433f51438a8662f35fa84ce2d7" uuid="55479a62c4ed7e3536b6e6f339ce05a802a81b9d" name="latch_1" x="336" y="210">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet i" sha="9c18b5ec0ea721bb98852ab326891478ca87a360" uuid="aae2176b26209e34e4fdeba5edb1ace82d178655" name="Out1" x="434" y="210">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet b" sha="17c8e188371661163bfa55cea9974eecb785fb06" uuid="3b0d3eacb5bb978cb05d1372aa2714d5a4790844" name="ToggleIn" x="42" y="252">
      <params/>
      <attribs/>
   </obj>
   <obj type="logic/samplehold" sha="689ed4c57ac833433f51438a8662f35fa84ce2d7" uuid="55479a62c4ed7e3536b6e6f339ce05a802a81b9d" name="latch_2" x="336" y="294">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/outlet i" sha="9c18b5ec0ea721bb98852ab326891478ca87a360" uuid="aae2176b26209e34e4fdeba5edb1ace82d178655" name="Out2" x="434" y="294">
      <params/>
      <attribs/>
   </obj>
   <obj type="logic/inv" sha="a8bfe6f6bbfd2a76e25328c139315bc7aa2a6e18" uuid="2bd44b865d3b63ff9b80862242bf5be779e3ad5" name="inv_1" x="196" y="308">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="ToggleIn" outlet="inlet"/>
         <dest obj="demux_3" inlet="s"/>
         <dest obj="latch_1" inlet="s_h"/>
         <dest obj="inv_1" inlet="i"/>
      </net>
      <net>
         <source obj="demux_3" outlet="o1"/>
         <dest obj="latch_2" inlet="in"/>
      </net>
      <net>
         <source obj="demux_3" outlet="o0"/>
         <dest obj="latch_1" inlet="in"/>
      </net>
      <net>
         <source obj="inv_1" outlet="o"/>
         <dest obj="latch_2" inlet="s_h"/>
      </net>
      <net>
         <source obj="latch_1" outlet="out"/>
         <dest obj="Out1" inlet="outlet"/>
      </net>
      <net>
         <source obj="latch_2" outlet="out"/>
         <dest obj="Out2" inlet="outlet"/>
      </net>
      <net>
         <source obj="IntIn" outlet="inlet"/>
         <dest obj="demux_3" inlet="i"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>86</x>
      <y>178</y>
      <width>625</width>
      <height>548</height>
   </windowPos>
</patch-1.0>