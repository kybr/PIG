source ~/.config/nvim/init.vim
set runtimepath+=./
autocmd TextChanged,TextChangedI *.glsl lua require"pig".send_code()
" nvim -u pig.vim foo.glsl
