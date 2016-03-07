#spartsi - TreeStructInfo 2.0 api for C++ >= 14

##Looking for something interesting?
Check out some integration tests!
https://github.com/spartanPAGE/spartsi/tree/master/spartsi/test/parser/impl/integration


## Example usage
```C++
std::string source = SPARTSI_STRF('#',
    treestructinfo "2.0"    #
      attr normal "1"       #

      node normal           #
        attr normal "2"     #
        ref attr ref        #
      end node              #

      ref node ref          #
    end tree                #

    ref attr ref "3"        #

    ref node ref            #
      ref attr ref          #
    end ref node            #

    ref attr ref "4"        #
);

//done
auto tree = spartsi::parse(source);
```