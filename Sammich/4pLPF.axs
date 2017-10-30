<patch-1.0 appVersion="1.0.12">
   <comment type="patch/comment" x="84" y="42" text="a filter based on pd&apos;s 4poleLP~"/>
   <obj type="patch/inlet a" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="filter in L" x="84" y="56">
      <params/>
      <attribs/>
   </obj>
   <obj type="filter/vcf" uuid="2b0aad6aeb06cc86c5802d2f167e9f281d8c35e1" name="vcf_1" x="336" y="56">
      <params/>
      <attribs/>
   </obj>
   <obj type="filter/hp1" uuid="abea7276611b289bed35b80345a6bc4efd4d9a4e" name="hp freq" x="434" y="56">
      <params>
         <frac32.s.map name="freq" value="-41.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="Filter Out L" x="532" y="56">
      <params/>
      <attribs/>
   </obj>
   <obj type="patch/inlet a" uuid="b577fe41e0a6bc7b5502ce33cb8a3129e2e28ee5" name="Filter in R" x="84" y="98">
      <params/>
      <attribs/>
   </obj>
   <obj type="ctrl/dial p" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="vcf freq" x="182" y="98">
      <params>
         <frac32.u.map name="value" onParent="true" value="0.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="filter/vcf" uuid="2b0aad6aeb06cc86c5802d2f167e9f281d8c35e1" name="vcf_2" x="336" y="126">
      <params/>
      <attribs/>
   </obj>
   <obj type="ctrl/dial p" uuid="cc5d2846c3d50e425f450c4b9851371b54f4d674" name="vcf res" x="84" y="196">
      <params>
         <frac32.u.map name="value" onParent="true" value="0.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="math/*c" uuid="7d5ef61c3bcd571ee6bbd8437ef3612125dfb225" name="*c_1" x="154" y="196">
      <params>
         <frac32.u.map name="amp" value="57.75000000000002"/>
      </params>
      <attribs/>
   </obj>
   <obj type="filter/vcf" uuid="2b0aad6aeb06cc86c5802d2f167e9f281d8c35e1" name="vcf_3" x="336" y="224">
      <params/>
      <attribs/>
   </obj>
   <obj type="filter/hp1" uuid="abea7276611b289bed35b80345a6bc4efd4d9a4e" name="hp freq_" x="434" y="224">
      <params>
         <frac32.s.map name="freq" value="-41.0"/>
      </params>
      <attribs/>
   </obj>
   <obj type="patch/outlet a" uuid="abd8c5fd3b0524a6630f65cad6dc27f6c58e2a3e" name="Filter Out R" x="532" y="224">
      <params/>
      <attribs/>
   </obj>
   <obj type="filter/vcf" uuid="2b0aad6aeb06cc86c5802d2f167e9f281d8c35e1" name="vcf_4" x="336" y="294">
      <params/>
      <attribs/>
   </obj>
   <nets>
      <net>
         <source obj="vcf_1" outlet="out"/>
         <dest obj="vcf_2" inlet="in"/>
      </net>
      <net>
         <source obj="filter in L" outlet="inlet"/>
         <dest obj="vcf_1" inlet="in"/>
      </net>
      <net>
         <source obj="vcf_2" outlet="out"/>
         <dest obj="hp freq" inlet="in"/>
      </net>
      <net>
         <source obj="hp freq" outlet="out"/>
         <dest obj="Filter Out L" inlet="outlet"/>
      </net>
      <net>
         <source obj="vcf freq" outlet="out"/>
         <dest obj="vcf_1" inlet="frequency"/>
         <dest obj="vcf_2" inlet="frequency"/>
         <dest obj="vcf_3" inlet="frequency"/>
         <dest obj="vcf_4" inlet="frequency"/>
      </net>
      <net>
         <source obj="*c_1" outlet="out"/>
         <dest obj="vcf_1" inlet="reso"/>
         <dest obj="vcf_2" inlet="reso"/>
         <dest obj="vcf_3" inlet="reso"/>
         <dest obj="vcf_4" inlet="reso"/>
      </net>
      <net>
         <source obj="vcf res" outlet="out"/>
         <dest obj="*c_1" inlet="in"/>
      </net>
      <net>
         <source obj="vcf_3" outlet="out"/>
         <dest obj="vcf_4" inlet="in"/>
      </net>
      <net>
         <source obj="Filter in R" outlet="inlet"/>
         <dest obj="vcf_3" inlet="in"/>
      </net>
      <net>
         <source obj="vcf_4" outlet="out"/>
         <dest obj="hp freq_" inlet="in"/>
      </net>
      <net>
         <source obj="hp freq_" outlet="out"/>
         <dest obj="Filter Out R" inlet="outlet"/>
      </net>
   </nets>
   <settings>
      <subpatchmode>no</subpatchmode>
   </settings>
   <notes><![CDATA[]]></notes>
   <windowPos>
      <x>391</x>
      <y>284</y>
      <width>887</width>
      <height>651</height>
   </windowPos>
</patch-1.0>