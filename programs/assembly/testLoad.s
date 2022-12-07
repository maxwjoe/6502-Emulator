         lda   #$15

         .org  $AAAA
         LDX   #$04
         LDA   ($02,X)

         .org  $fffc
         JSR   $AAAA


